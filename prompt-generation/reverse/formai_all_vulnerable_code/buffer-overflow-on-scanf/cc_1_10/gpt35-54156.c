//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to read the ebook file
int read_ebook(char *filename, char *buffer) {
    FILE *fp;
    int size = 0;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return -1;
    }
    size = fread(buffer, sizeof(char), MAX_SIZE, fp);
    fclose(fp);
    return size;
}

// Function to print the ebook
void print_ebook(char *buffer) {
    printf("\n---------------------------------START----------------------------------\n");
    printf("%s", buffer);
    printf("\n---------------------------------END------------------------------------\n");
}

// Function to encode the ebook
void encode_ebook(char *buffer) {
    for(int i = 0; buffer[i] != 0; i++) {
        buffer[i] = (char)((int)buffer[i] + 20);
    }
}

// Function to decode the ebook
void decode_ebook(char *buffer) {
    for(int i = 0; buffer[i] != 0; i++) {
        buffer[i] = (char)((int)buffer[i] - 20);
    }
}

int main() {
    printf("Welcome to the Surrealist Ebook Reader!\n");
    char filename[MAX_SIZE];
    char buffer[MAX_SIZE];
    int size = 0;
    printf("Please enter the name of the ebook file: ");
    scanf("%s",filename);
    size = read_ebook(filename, buffer);
    if(size > 0) {
        printf("\nEbook loaded successfully!\n");
        printf("\nDo you want to encode the ebook? Press E to encode or any other key to continue: ");
        char choice;
        scanf(" %c",&choice);
        if(choice == 'E' || choice == 'e') {
            encode_ebook(buffer);
            printf("\nEbook encoded successfully!\n");
        }
        printf("\nDo you want to decode the ebook? Press D to decode or any other key to continue: ");
        scanf(" %c",&choice);
        if(choice == 'D' || choice == 'd') {
            decode_ebook(buffer);
            printf("\nEbook decoded successfully!\n");
        }
        printf("\nDo you want to print the ebook? Press P to print or any other key to exit: ");
        scanf(" %c",&choice);
        if(choice == 'P' || choice == 'p') {
            print_ebook(buffer);
        }
    }
    printf("\nThank you for using the Surrealist Ebook Reader!\n");
    return 0;
}