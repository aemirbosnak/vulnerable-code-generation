//FormAI DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main(){
    FILE *file;
    char name[MAX_SIZE], message[MAX_SIZE];
    int choice;
    
    printf("Hello there! What's your name?\n");
    scanf("%s", name);

    printf("\n%s, welcome to our love story...\n", name);

    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Write a love letter to your beloved\n");
        printf("2. Read a love letter from your beloved\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nWrite your love letter here:\n");
                scanf(" %[^\n]s", message);

                file = fopen("love_letter.txt", "a");

                if(file == NULL){
                    printf("\nError opening file!");
                    exit(1);
                }

                fprintf(file, "%s: %s\n", name, message);
                printf("\nYour love letter has been saved!");

                fclose(file);
                break;

            case 2:
                file = fopen("love_letter.txt", "r");

                if(file == NULL){
                    printf("\nNo love letters to read!");
                    break;
                }

                printf("\nHere are the letters from your beloved...\n");

                char line[MAX_SIZE];
                while(fgets(line, MAX_SIZE, file) != NULL){
                    printf("%s", line);
                }

                fclose(file);
                break;

            case 3:
                printf("\nGoodbye, my love. Until we meet again...");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again...");
        }
    }

    return 0;
}