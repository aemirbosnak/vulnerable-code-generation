//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MARK "2093040" // watermark ID

// function prototypes
void embed_mark(char *text);
void extract_mark(char *text);

int main()
{
    char text[MAX_TEXT_LENGTH];
    int choice;

    printf("Enter text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    do {
        printf("Choose an option:\n");
        printf("1. Embed watermark\n");
        printf("2. Extract watermark\n");
        printf("3. Exit\n");

        scanf("%d", &choice);
        getchar();  // absorb newline character

        switch(choice) {
            case 1:
                embed_mark(text);
                break;
            case 2:
                extract_mark(text);
                break;
            case 3:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}

void embed_mark(char *text)
{
    char *mark = MARK;
    char *pos = strstr(text, mark);

    if(pos != NULL) {
        printf("Watermark already embedded.\n");
        return;
    }

    // embed watermark at the end of text
    strcat(text, mark);
    printf("Watermark embedded successfully.\n");
}

void extract_mark(char *text)
{
    char *pos = strstr(text, MARK);

    if(pos == NULL) {
        printf("Watermark not found.\n");
        return;
    }

    int len = strlen(text) - strlen(MARK);
    char *extracted_text = calloc(len + 1, sizeof(char)); // allocate memory for extracted text
    strncpy(extracted_text, text, len); // copy text without watermark to extracted_text

    printf("Watermark extracted successfully.\n");
    printf("Extracted Text: %s\n", extracted_text);

    free(extracted_text); // free memory
}