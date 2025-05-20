//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my fantastic C File Handling program!\n");
    printf("Get ready to have your mind blown by the incredible power of C File Handling!\n");

    FILE *fp;
    char filename[30], content[100];

    printf("Enter the name of your file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Uh oh, looks like something went wrong! Unable to create file.");
        exit(1);
    } else {
        printf("Yay! We have created a file named %s\n", filename);
    }

    printf("What do you want to write in your file? Write here: ");
    scanf("%s", content);

    fputs(content, fp);
    printf("%s written to %s successfully!", content, filename);

    fclose(fp);

    printf("Now, let's read the contents of our file!\n");

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Oh no, something went wrong again! Unable to read the file.");
        exit(1);
    }

    printf("The contents of file %s are:\n", filename);

    char ch = fgetc(fp);
    while (ch != EOF) {
        putchar(ch);
        ch = fgetc(fp);
    }

    fclose(fp);

    printf("Thank you for using my exciting C File Handling program!\n");
    printf("I hope you feel empowered to use C File Handling capabilities in your own projects!\n");

    return 0;
}