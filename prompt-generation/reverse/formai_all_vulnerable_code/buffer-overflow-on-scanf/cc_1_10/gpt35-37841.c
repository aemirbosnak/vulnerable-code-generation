//FormAI DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char **argv) {

    FILE *fp;
    char data_buffer[MAX_DATA_SIZE];
    char recovered_data[MAX_DATA_SIZE];
    size_t position;
    long int file_size;
    int i, selection;

    printf("Welcome to Paranoid Data Recovery Tool\n");
    printf("-------------------------------------\n");
    printf("Please select from the following options: \n");
    printf("1. Recover corrupted data\n");
    printf("2. Recover deleted data\n");
    printf("3. Quit\n");
    scanf("%d", &selection);

    switch (selection) {

        case 1:
            printf("Please enter the name of the file you want to recover:\n");
            scanf("%s", data_buffer);
            fp = fopen(data_buffer, "rb");

            if (fp == NULL) {
                printf("Error: File not found\n");
                return 0;
            }

            fseek(fp, 0, SEEK_END);
            file_size = ftell(fp);
            rewind(fp);

            printf("Total file size: %lu bytes\n", file_size);

            position = 0;
            while (position < file_size) {
                fread(recovered_data, sizeof(char), MAX_DATA_SIZE, fp);
                for (i = 0; i < MAX_DATA_SIZE; i++) {
                    recovered_data[i] ^= 0xFF;
                }
                fwrite(recovered_data, sizeof(char), MAX_DATA_SIZE, stdout);
                position += MAX_DATA_SIZE;
            }
            fclose(fp);
            break;

        case 2:
            printf("Please enter the name of the file you want to recover:\n");
            scanf("%s", data_buffer);
            fp = fopen(data_buffer, "rb");

            if (fp == NULL) {
                printf("Error: File not found\n");
                return 0;
            }

            fseek(fp, 0, SEEK_END);
            file_size = ftell(fp);
            rewind(fp);

            printf("Total file size: %lu bytes\n", file_size);

            position = 0;
            while (position < file_size) {
                fread(recovered_data, sizeof(char), MAX_DATA_SIZE, fp);
                for (i = 0; i < MAX_DATA_SIZE; i++) {
                    recovered_data[i] ^= 0xAA;
                }
                fwrite(recovered_data, sizeof(char), MAX_DATA_SIZE, stdout);
                position += MAX_DATA_SIZE;
            }
            fclose(fp);
            break;

        case 3:
            printf("Exiting Paranoid Data Recovery Tool...\n");
            break;

        default:
            printf("Invalid selection\n");
            break;
    }

    return 0;
}