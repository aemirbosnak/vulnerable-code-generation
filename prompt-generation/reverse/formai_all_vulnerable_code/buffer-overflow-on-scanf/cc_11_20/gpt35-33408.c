//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;     // File pointer
    char c;         // Character to hold each character in file

    printf("Welcome to My C Ebook Reader!\n");

    // Ask user for filename
    char filename[30];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file and check for errors
    file = fopen(filename, "r");
    if (file == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    // Print first page
    printf("\nPAGE 1:\n\n");
    int count = 0;
    while (count < 50 && (c = getc(file)) != EOF){
        putchar(c);
        if (c == '\n')
            count++;
    }

    // Ask user if they want to continue reading
    char response;
    do{
        printf("\nDo you want to keep reading? (y/n): ");
        scanf(" %c", &response);
        if (response != 'y' && response != 'n')
            printf("Invalid response. ");
    } while (response != 'y' && response != 'n');

    // Keep displaying pages until user says no
    int page = 1;
    while (response == 'y' && (c = getc(file)) != EOF){
        if (c == '\f'){     // New page
            page++;
            printf("\nPAGE %d:\n\n", page);
            count = 0;      // Reset line count for next page
        } else {
            putchar(c);
            if (c == '\n')
                count++;
        }

        // Check if page limit has been reached
        if (count == 50){
            printf("\nDo you want to keep reading? (y/n): ");
            scanf(" %c", &response);
            if (response != 'y' && response != 'n')
                printf("Invalid response. ");
            count = 0;
        }
    }

    // Close file
    fclose(file);

    printf("\nEnd of file.\n");

    return 0;
}