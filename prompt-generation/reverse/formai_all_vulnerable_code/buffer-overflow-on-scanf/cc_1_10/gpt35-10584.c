//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>

int main() {
    printf("Hello, everyone! Are you ready to learn about file handling in C?? Let's get started!\n\n");

    FILE *file_pointer;
    char file_name[100];
    printf("First, let's create a new file. What should we call it?\n");
    scanf("%s", file_name);

    file_pointer = fopen(file_name, "w");
    if (file_pointer == NULL) {
        printf("Uh oh, there was an error creating the file. Our program will now exit.\n");
        return 1;
    }
    printf("Great! We successfully created the file %s.\n\n", file_name);

    printf("Now let's write something to the file. What would you like to say?\n");
    char message[100];
    scanf(" %[^\n]s", message);
    fprintf(file_pointer, "%s", message);

    printf("Awesome! We wrote the message \"%s\" to the file %s.\n\n", message, file_name);

    printf("Next, let's read the contents of the file. Here's what's in %s:\n", file_name);
    fclose(file_pointer);
    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Uh oh, there was an error opening the file. Our program will now exit.\n");
        return 1;
    }
    char character;
    while ((character = getc(file_pointer)) != EOF) {
        printf("%c", character);
    }
    printf("\n\nWow, that was awesome! We successfully read the contents of the file %s.\n\n", file_name);

    printf("Finally, let's delete the file. Are you sure you want to delete %s? (y/n)\n", file_name);
    char response;
    scanf(" %c", &response);
    if (response == 'y') {
        remove(file_name);
        printf("The file %s has been deleted. Thanks for using our program!\n\n", file_name);
    } else {
        printf("Great! The file %s has not been deleted. Thanks for using our program!\n\n", file_name);
    }

    fclose(file_pointer);
    return 0;
}