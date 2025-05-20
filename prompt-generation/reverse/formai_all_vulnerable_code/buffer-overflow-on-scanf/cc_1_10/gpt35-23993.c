//FormAI DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char file_name[50];
    FILE *fptr;
    char c;

    printf("Enter the file name to be opened: ");
    scanf("%s", file_name);

    fptr = fopen(file_name, "r");
    if (fptr == NULL){
        printf("Error: File not found\n");
        exit(0);
    }

    printf("\nOriginal HTML Code:\n\n");

    // Read and print the original HTML code
    c = fgetc(fptr);
    while (c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);

    fptr = fopen(file_name, "r");
    if (fptr == NULL){
        printf("Error: File not found\n");
        exit(0);
    }

    printf("\nFormatted HTML Code:\n\n");

    // Read and format the HTML code
    int indent_level = 0;
    c = fgetc(fptr);
    while (c != EOF){
        if (c == '<'){
            printf("\n");
            for (int i = 0; i < indent_level; i++){
                printf("\t");
            }
            printf("%c", c);
            indent_level++;
        }
        else if (c == '>'){
            printf("%c", c);
            indent_level--;
        }
        else{
            printf("%c", c);
        }
        c = fgetc(fptr);
    }
    fclose(fptr);

    printf("\n\nHTML code successfully beautified!");

    return 0;
}