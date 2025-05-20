//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_DATA_SIZE 1024

void print_intro() {
    printf("Welcome to the Data Recovery Tool!\n\n");
    printf("We specialize in recovering lost or corrupted data from C programs.\n");
    printf("Our methods are top secret, and we won't reveal our tricks to just anyone.\n");
    printf("But if your program is in trouble, then we're the ones you need to call!\n\n");
}

void print_prompt() {
    printf("\n>> ");
}

void print_goodbye() {
    printf("Thank you for choosing the Data Recovery Tool. Good luck with your program!\n");
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    char data[MAX_DATA_SIZE];
    FILE* fp = NULL;
    int data_size = 0;

    print_intro();

    while (1) {
        printf("Please enter the name of the file you want to recover: ");
        scanf("%s", filename);

        fp = fopen(filename, "rb");

        if (fp == NULL) {
            printf("Sorry, we couldn't open that file. Please try again.\n");
            continue;
        }

        fseek(fp, 0, SEEK_END);
        data_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        if (data_size > MAX_DATA_SIZE) {
            printf("Sorry, that file is too big for us to handle. Please choose another.\n");
            fclose(fp);
            continue;
        }

        fread(data, sizeof(char), data_size, fp);

        if (ferror(fp)) {
            printf("Sorry, there was an error reading the file. Please choose another.\n");
            fclose(fp);
            continue;
        }

        fclose(fp);

        printf("We have successfully recovered the following data from your file:\n\n");

        printf("%s\n", data);

        break;
    }

    print_goodbye();

    return 0;
}