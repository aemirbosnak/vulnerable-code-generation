//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void weirdFile(char* fileName) {
    srand(time(NULL));
    int numLines = rand() % 100 + 1;
    FILE* file = fopen(fileName, "w");

    for(int i = 0; i < numLines; i++) {
        int numChars = rand() % 100 + 1;
        for(int j = 0; j < numChars; j++) {
            char c = rand() % 128;
            fputc(c, file);
        }
        fputc('\n', file);
    }

    fclose(file);

    printf("A strange file has been generated: %s\n", fileName);
}


int main() {
    char fileName[50];
    printf("Welcome to this surreal program.\n");

    printf("Please enter the name of the file you want to create: ");
    scanf("%s", fileName);

    weirdFile(fileName);

    int option;
    printf("What do you want to do with this weird file?\n");
    printf("1. Read it backwards\n");
    printf("2. Replace all vowels with the letter 'Z'\n");
    printf("3. Remove all even lines\n");
    printf("4. Exit\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1: {
            printf("Reading the file backwards...\n");
            FILE* file = fopen(fileName, "r");

            fseek(file, 0, SEEK_END);
            long fileSize = ftell(file);
            char* fileContents = malloc(fileSize);

            fseek(file, 0, SEEK_SET);
            fread(fileContents, 1, fileSize, file);

            for(int i = fileSize - 1; i >= 0; i--) {
                printf("%c", fileContents[i]);
            }

            fclose(file);
            free(fileContents);
            break;
        }
        case 2: {
            printf("Replacing vowels with 'Z'...\n");
            FILE* file = fopen(fileName, "r+");
            
            char c;
            while((c = fgetc(file)) != EOF) {
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    fseek(file, -1, SEEK_CUR);
                    fputc('Z', file);
                }
            }

            fclose(file);
            break;
        }
        case 3: {
            printf("Removing even lines...\n");
            FILE* file = fopen(fileName, "r+");
            FILE* tempFile = fopen("temp_file.txt", "w");

            int lineCounter = 1;
            char c;
            while((c = fgetc(file)) != EOF) {
                if(lineCounter % 2 == 1) {
                    fputc(c, tempFile);
                }
                if(c == '\n') {
                    lineCounter++;
                }
            }

            fclose(file);
            fclose(tempFile);

            remove(fileName);
            rename("temp_file.txt", fileName);
            break;
        }
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}