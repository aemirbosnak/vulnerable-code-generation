//FormAI DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char ch, fileName[20], data[100];
    int choice, index, count=0;
    long int size;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("File does not exist.\n");
        exit(0);
    }

    printf("Choose the option you want to perform:\n");
    printf("1. Check file size.\n");
    printf("2. Read all file data.\n");
    printf("3. Recover deleted data.\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            fseek(fp, 0L, SEEK_END);
            size = ftell(fp);
            printf("File size is %ld bytes.\n", size);
            break;
        case 2:
            while((ch = fgetc(fp)) != EOF){
                printf("%c", ch);
            }
            break;
        case 3:
            printf("Enter the index where you want to start data recovery: ");
            scanf("%d", &index);
            fseek(fp, index, SEEK_SET);
            while((ch = fgetc(fp)) != EOF){
                data[count++] = ch;
            }
            printf("Recovered data is: %s\n", data);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    fclose(fp);

    return 0;
}