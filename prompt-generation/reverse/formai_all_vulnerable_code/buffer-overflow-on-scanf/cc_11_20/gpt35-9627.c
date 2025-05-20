//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    FILE *fp;
    char c;
    int line = 1, page = 1;

    printf("Enter the name of the file you wish to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("============================\n");
    printf("         EBOOK READER       \n");
    printf("============================\n");

    printf("Press P to go to the next page.\n");
    printf("Press L to go to the next line.\n");
    printf("Press Q to quit.\n");

    while ((c = fgetc(fp)) != EOF) {
        if (line == 1 && page == 1) {
            printf("======== PAGE %d ========\n", page);
        }
        putchar(c);

        if (c == '\n') {
            line++;
        }

        if (line == 60) {
            printf("============================\n");
            printf("PAGE %d ENDED. PRESS P TO CONTINUE.\n", page);
            printf("============================\n");

            while ((c = getchar()) != 'p' && c != 'P' && c != 'q' && c != 'Q') {
            }

            if (c == 'q' || c == 'Q') {
                break;
            }

            printf("============================\n");
            printf("         EBOOK READER       \n");
            printf("============================\n");

            page++;
            line = 1;
        }
    }

    printf("\n");

    fclose(fp);

    return 0;
}