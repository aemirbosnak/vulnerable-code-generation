//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char filename[20], name[20], color[20], line[50];
    int option, age;
    FILE *file;

    printf("Please enter the name of the file you want to create: ");
    scanf("%s", filename);

    file = fopen(filename, "w+");

    if(file == NULL){
        printf("ERROR: Unable to open or create file.\n");
        return 1;
    }

    printf("\nWelcome to the pet registration system!\n");

    do{
        printf("\nPlease select an option:\n");
        printf("1. Register a new pet\n");
        printf("2. View registered pets\n");
        printf("3. Exit the program\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nPlease enter the following information:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Age: ");
                scanf("%d", &age);
                printf("Color: ");
                scanf("%s", color);

                fprintf(file, "%s %d %s\n", name, age, color);
                break;

            case 2:
                printf("\nRegistered pets:\n");
                rewind(file);
                fgets(line, 50, file);

                while(!feof(file)){
                    printf("%s", line);
                    fgets(line, 50, file);
                }

                break;

            case 3:
                printf("\nThank you for using the pet registration system!\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }

    } while(option != 3);

    fclose(file);

    return 0;
}