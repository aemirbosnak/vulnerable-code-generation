//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
/* The Not-So-Simple Compression Algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1000

void compress(char* input, char* output)
{
    char buffer[BUFF_SIZE];
    char curr_char;
    int count, buffer_pos, i, j;

    FILE* f_in = fopen(input, "r");
    FILE* f_out = fopen(output, "w");

    if(f_in == NULL || f_out == NULL) {
        printf("Error opening file(s).\n");
        exit(EXIT_FAILURE);
    }

    buffer_pos = 0;
    count = 1;
    curr_char = fgetc(f_in);

    while(curr_char != EOF) {
        buffer[buffer_pos++] = curr_char;

        for(i = buffer_pos; i < BUFF_SIZE && curr_char == fgetc(f_in); i++) {
            count++;
            if(count >= 9) {
                buffer[buffer_pos-1] = count + '0';
                buffer_pos = i;
                count = 1;
                break;
            }
        }

        if(count < 9) {
            buffer[buffer_pos-1] = count + '0';
            buffer_pos = i - 1;
            count = 1;
        }

        if(buffer_pos == BUFF_SIZE || curr_char == EOF) {
            for(j = 0; j < buffer_pos; j++) {
                putc(buffer[j], f_out);
            }
            buffer_pos = 0;
        }

        curr_char = fgetc(f_in);
    }

    fclose(f_in);
    fclose(f_out);

    printf("\nCompression successful!\n");
}

void decompress(char* input, char* output)
{
    char buffer[BUFF_SIZE];
    char curr_char;
    int i, j, count;
    FILE* f_in = fopen(input, "r");
    FILE* f_out = fopen(output, "w");

    if(f_in == NULL || f_out == NULL) {
        printf("Error opening file(s).\n");
        exit(EXIT_FAILURE);
    }

    curr_char = fgetc(f_in);

    while(curr_char != EOF) {
        count = curr_char - '0';

        for(i = 0; i < count; i++) {
            buffer[i] = fgetc(f_in);
        }

        for(j = 0; j < count; j++) {
            putc(buffer[i], f_out);
        }

        curr_char = fgetc(f_in);
    }

    fclose(f_in);
    fclose(f_out);

    printf("\nDecompression successful!\n");
}

int main()
{
    char input_file[50], compressed_file[50], decompressed_file[50];
    int choice;

    printf("*** The Not-So-Simple Compression Algorithm ***\n");
    printf("\nChoose an option:\n");
    printf("1. Compress a file.\n");
    printf("2. Decompress a file.\n");
    printf("3. Quit.\n\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter the name of the file to compress: ");
            scanf("%s", input_file);
            strcpy(compressed_file, "compressed_");
            strcat(compressed_file, input_file);
            compress(input_file, compressed_file);
            break;

        case 2:
            printf("\nEnter the name of the file to decompress: ");
            scanf("%s", compressed_file);
            printf("\nEnter the name of the decompressed file: ");
            scanf("%s", decompressed_file);
            decompress(compressed_file, decompressed_file);
            break;

        case 3:
            exit(EXIT_SUCCESS);

        default:
            printf("\nInvalid choice. Exiting...\n");
            exit(EXIT_FAILURE);
    }

    return 0;
}