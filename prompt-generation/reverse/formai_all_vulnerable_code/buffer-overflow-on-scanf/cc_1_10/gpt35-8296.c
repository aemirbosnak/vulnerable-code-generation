//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char message[MAX_FILE_SIZE];
    char watermark[] = "this is a digital watermark";
    char filename[100];
    FILE *file;
    int ch, index = 0, watermark_index = 0;
    
    printf("Enter the name of the file you want to watermark: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    
    while ((ch = fgetc(file)) != EOF && index < MAX_FILE_SIZE) {
        message[index] = ch;
        index++;
    }
    message[index] = '\0';
    
    fclose(file);
    
    if (index == 0) {
        printf("File is empty.\n");
        return 1;
    }
    
    int message_length = strlen(message);
    int watermark_length = strlen(watermark);
    int i, j;
    
    for (i = 0; i < message_length; i++) {
        if (message[i] == ' ') {
            watermark_index = 0;
            continue;
        }
        if (watermark_index == watermark_length) {
            break;
        }
        message[i] = (message[i] + watermark[watermark_index]) % 256;
        watermark_index++;
    }
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    fwrite(message, 1, message_length, file);
    fclose(file);
    
    printf("Watermark written to file successfully.\n");
    
    return 0;
}