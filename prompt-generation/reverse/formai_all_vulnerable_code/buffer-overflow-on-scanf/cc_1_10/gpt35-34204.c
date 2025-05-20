//FormAI DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eBook{
    char title[50];
    char author[50];
    int publicationYear;
    float price;
    char filename[100];
};

int main(int argc, char *argv[]) {
    struct eBook book;
    char fileType[4] = "txt";
    char command[100];

    printf("Please enter the eBook title: \n");
    fgets(book.title, sizeof(book.title), stdin);

    printf("Please enter the eBook author: \n");
    fgets(book.author, sizeof(book.author), stdin);

    printf("Please enter the eBook publication year: \n");
    scanf("%d", &book.publicationYear);
    getchar();

    printf("Please enter the eBook price: \n");
    scanf("%f", &book.price);
    getchar();

    printf("Please enter the eBook filename: \n");
    fgets(book.filename, sizeof(book.filename), stdin);

    // check if file exists
    FILE *fp;
    fp = fopen(book.filename, "r");
    
    if (fp == NULL) { // file does not exist
        printf("File does not exist.\n");
        printf("Please try again with a valid filename.\n");
        return 1;
    } else { // file exists
        fclose(fp);

        // check if file is txt file
        char *ext = strrchr(book.filename, '.');
        if (ext == NULL || strcmp(ext+1, fileType) != 0) {
            printf("File must be a txt file.\n");
            printf("Please try again with a valid txt file.\n");
            return 1;
        }
    }

    // display eBook information
    printf("\n----------\n");
    printf("Title: %s", book.title);
    printf("Author: %s", book.author);
    printf("Publication Year: %d\n", book.publicationYear);
    printf("Price: $%.2f\n", book.price);
    printf("Filename: %s", book.filename);
    printf("----------\n\n");
    
    // open and display eBook file
    printf("Would you like to open the eBook? (y/n)\n");
    fgets(command, sizeof(command), stdin);
    
    if (strcmp(command, "y\n") == 0 || strcmp(command, "Y\n") == 0) { // open file
        char openCommand[100];

        #ifdef __unix__
            sprintf(openCommand, "xdg-open %s", book.filename);
        #elif defined(_WIN32) || defined(WIN32)
            sprintf(openCommand, "start %s", book.filename);
        #else
            printf("Cannot open eBook on this platform.\n");
            printf("Please try again on a different platform.\n");
            return 1;
        #endif

        system(openCommand);
    } else { // don't open file
        printf("EBook will not be opened.\n");
    }

    return 0;
}