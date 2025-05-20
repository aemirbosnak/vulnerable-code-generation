//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

/**
 * Function to read the contents of a file
 * @param filename: File name to read
 * @param file_content: Pointer to read file content
 * @return Size of the file read
 */
int read_file_content(const char* filename, char** file_content) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(-1);
    }
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    *file_content = (char*)malloc(sizeof(char) * (file_size + 1));
    fread(*file_content, sizeof(char), file_size, fp);
    (*file_content)[file_size] = '\0';
    fclose(fp);
    return file_size;
}

/**
 * Function to write the contents to a file
 * @param filename: File name to write
 * @param file_content: Pointer to write file content
 * @param file_size: Size of the file to be written
 */
void write_file_content(const char* filename, char* file_content, int file_size) {
    FILE* fp = fopen(filename, "w+");
    if(fp == NULL) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        exit(-1);
    }
    fwrite(file_content, sizeof(char), file_size, fp);
    fclose(fp);
}

/**
 * Function to embed the digital watermark into the original message
 * @param message: Message to embed the digital watermark
 * @param watermark: Digital watermark
 * @return: Message with digital watermark
 */
char* embed_watermark(const char* message, const char* watermark) {
    int message_len = strlen(message);
    int watermark_len = strlen(watermark);
    char* message_watermark = (char*)malloc(sizeof(char) * (message_len + watermark_len + 1));
    for(int i = 0; i < message_len; i++) {
        message_watermark[i] = message[i];
    }
    for(int j = 0; j < watermark_len; j++) {
        message_watermark[message_len + j] = watermark[j];
    }
    message_watermark[message_len + watermark_len] = '\0';
    return message_watermark;    
}

/**
 * Function to extract the digital watermark from the message
 * @param message: Message with digital watermark
 * @param watermark_len: Size of the digital watermark to be extraced
 * @return: Extracted digital watermark
 */
char* extract_watermark(const char* message, int watermark_len) {
    int message_len = strlen(message);
    char* watermark = (char*)malloc(sizeof(char) * (watermark_len + 1));
    for(int i = 0; i < watermark_len; i++) {
        watermark[i] = message[message_len - watermark_len + i];
    }
    watermark[watermark_len] = '\0';
    return watermark;
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("Usage: %s [embed|extract] [message file] [watermark file]\n", argv[0]);
        exit(-1);
    }
    char* message_content = NULL;
    char* watermark_content = NULL;
    int message_size = read_file_content(argv[2], &message_content);
    int watermark_size = read_file_content(argv[3], &watermark_content);
    if(strcmp(argv[1], "embed") == 0) {
        char* message_watermark = embed_watermark(message_content, watermark_content);
        write_file_content("output.txt", message_watermark, message_size + watermark_size);
        printf("Digital watermark successfully embedded into the original message!\n");
    }
    else if(strcmp(argv[1], "extract") == 0) {
        int message_size_with_watermark = read_file_content(argv[2], &message_content);
        char* extracted_watermark = extract_watermark(message_content, watermark_size);
        write_file_content("watermark.txt", extracted_watermark, watermark_size);
        printf("Digital watermark successfully extracted from the message!\n");
    }
    else {
        printf("Usage: %s [embed|extract] [message file] [watermark file]\n", argv[0]);
    }
    if(message_content != NULL) {
        free(message_content);
    }
    if(watermark_content != NULL) {
        free(watermark_content);
    }
    return 0;
}