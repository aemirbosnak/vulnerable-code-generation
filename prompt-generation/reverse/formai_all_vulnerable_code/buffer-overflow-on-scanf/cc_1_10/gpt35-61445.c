//FormAI DATASET v1.0 Category: Data recovery tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "data.bin"
#define MAX_SIZE 1024

int main()
{
    int option;
    printf("\n========================================\n");
    printf("=   C Data Recovery Tool Example Program =\n");
    printf("========================================\n\n");

    while(1){
        printf("Select an option:\n");
        printf("1. Create new data\n");
        printf("2. Read existing data\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option){
            case 1:{
                char data[MAX_SIZE];
                printf("Enter data: ");
                scanf(" %[^\n]", data);

                FILE *file = fopen(DATA_FILE, "wb");
                if(file == NULL){
                    printf("Error opening file.\n");
                    exit(1);
                }
                fwrite(data, sizeof(char), strlen(data), file);
                fclose(file);
                printf("Data saved to %s.\n", DATA_FILE);
                break;
            }
            case 2:{
                FILE *file = fopen(DATA_FILE, "rb");
                if(file == NULL){
                    printf("Error opening file.\n");
                    exit(1);
                }

                fseek(file, 0, SEEK_END);
                long fileSize = ftell(file);
                fseek(file, 0, SEEK_SET);

                char *data = (char*) malloc(fileSize + 1);
                if(data == NULL){
                    printf("Error allocating memory.\n");
                    exit(1);
                }

                fread(data, sizeof(char), fileSize, file);
                data[fileSize] = '\0';
                printf("Data read from %s:\n%s\n", DATA_FILE, data);

                fclose(file);
                free(data);
                break;
            }
            case 3:{
                printf("Exiting program...\n");
                exit(0);
            }
            default:{
                printf("Invalid option.\n");
                break;
            }
        }
    }

    return 0;
}