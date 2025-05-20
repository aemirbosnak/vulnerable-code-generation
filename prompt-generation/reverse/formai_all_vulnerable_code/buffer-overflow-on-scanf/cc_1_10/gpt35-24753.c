//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WATERMARK_LENGTH 100
#define MAX_FILE_SIZE 100000

void embedWatermark(char *fileName, char *watermark){
    char buffer[MAX_FILE_SIZE];

    FILE *file = fopen(fileName, "rb");

    if(file == NULL){
        printf("File not found.\n");
        return;
    }

    // read file into buffer
    int bytesRead = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);

    fclose(file);

    // add watermark to buffer
    strcat(buffer, watermark);

    file = fopen(fileName, "wb");

    if(file == NULL){
        printf("Unable to write to file.\n");
        return;
    }

    // write updated contents to file
    fwrite(buffer, sizeof(char), bytesRead + strlen(watermark), file);

    printf("Successfully embedded watermark.\n");

    fclose(file);
}

void extractWatermark(char *fileName){
    char buffer[MAX_FILE_SIZE];
    char watermark[MAX_WATERMARK_LENGTH];
    int watermarkLength = 0;

    FILE *file = fopen(fileName, "rb");

    if(file == NULL){
        printf("File not found.\n");
        return;
    }

    // read file into buffer
    int bytesRead = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);

    fclose(file);

    // extract watermark from end of buffer
    for(int i = bytesRead-1; i >= 0; i--){
        if(buffer[i] == '|'){
            watermarkLength = bytesRead - i - 1;
            strncpy(watermark, buffer + i + 1, watermarkLength);
            break;
        }
    }

    printf("Extracted watermark: %s\n", watermark);

}

int main(){
    int choice;
    char filename[50], watermark[MAX_WATERMARK_LENGTH];

    do {
        printf("Watermarking Program\n");
        printf("--------------------\n");
        printf("1. Embed watermark\n");
        printf("2. Extract watermark\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter watermark (max %d characters): ", MAX_WATERMARK_LENGTH);
                scanf(" %[^\n]", watermark);
                strcat(watermark, "|");
                embedWatermark(filename, watermark);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                extractWatermark(filename);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}