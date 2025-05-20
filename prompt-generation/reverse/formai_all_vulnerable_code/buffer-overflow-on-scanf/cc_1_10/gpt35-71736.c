//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// This program is a C Ebook reader.
// It reads a book file in txt format and allows the user to read it in a comfortable way.

int main() {
    char filename[50];
    printf("Please enter the filename of the book you want to read (must be in txt format): ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    char line[100];
    int page_number = 1;
    int line_number = 1;
    int lines_per_page = 22;

    printf("**********\nC EBOOK READER\n**********\n");

    while (fgets(line, sizeof(line), fp)) {
        if (line_number == 1) {
            printf("Page %d\n", page_number);
            printf("--------------------------------------------------\n");
        }
        printf("%s", line);
        line_number++;

        // If the number of lines per page has been reached, wait for user input before displaying next page
        if (line_number > lines_per_page) {
            printf("--------------------------------------------------\n");
            printf("Press Enter to continue to the next page.\n");
            getchar();
            line_number = 1;
            page_number++;
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("**********\nC EBOOK READER\n**********\n");
        }
    }

    fclose(fp);
    printf("End of book.\n");

    return 0;
}