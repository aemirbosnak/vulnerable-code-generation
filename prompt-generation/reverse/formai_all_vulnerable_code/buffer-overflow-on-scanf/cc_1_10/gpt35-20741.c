//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file_ptr;
    char file_name[25];

    printf("Hey there, I heard you want to learn about file handling in C! How exciting!\n");
    printf("To get started, we need to create a new file. What would you like to name it? (25 characters and below)\n");

    scanf("%s", file_name);

    printf("Alright, let's create a file called %s and write to it!\n", file_name);

    file_ptr = fopen(file_name, "w+");

    if (file_ptr == NULL) {
        printf("Oops, couldn't create the file! Better luck next time!\n");
        exit(1);
    } else {
        printf("Congratulations! %s was created successfully!\n", file_name);
    }

    printf("Now, let's write a joke to the file. I hope you're ready!\n");

    fprintf(file_ptr, "Why did the tomato turn red? Because it saw the salad dressing!\n");

    printf("The joke has been written to the file!\n");

    fclose(file_ptr);

    printf("Now, let's read what we wrote in %s\n", file_name);

    file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL) {
        printf("Oops, couldn't open the file! Better luck next time!\n");
        exit(1);
    }

    char ch = fgetc(file_ptr);

    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(file_ptr);
    }

    fclose(file_ptr);

    printf("\nLooks like we're done here folks! Goodbye!");

    return 0;
}