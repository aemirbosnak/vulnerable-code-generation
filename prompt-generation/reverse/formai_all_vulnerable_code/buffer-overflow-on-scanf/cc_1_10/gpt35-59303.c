//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void createFile(char* fileName);
void addDataToFile(char* fileName);
void readDataFromFile(char* fileName);
void deleteDataFromFile(char* fileName);

int main()
{
    char fileName[20];
    int choice;
    do
    {
        printf("\n1. Create File");
        printf("\n2. Add Data to File");
        printf("\n3. Read Data from File");
        printf("\n4. Delete Data from File");
        printf("\n5. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter File Name to be Created: ");
                scanf("%s", fileName);
                createFile(fileName);
                break;
            case 2:
                printf("\nEnter File Name to Add Data: ");
                scanf("%s", fileName);
                addDataToFile(fileName);
                break;
            case 3:
                printf("\nEnter File Name to Read Data: ");
                scanf("%s", fileName);
                readDataFromFile(fileName);
                break;
            case 4:
                printf("\nEnter File Name to Delete Data: ");
                scanf("%s", fileName);
                deleteDataFromFile(fileName);
                break;
            case 5:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid Choice!!! Try Again...");
        }
    } while (choice != 5);
    return 0;
}

void createFile(char* fileName)
{
    FILE *fptr = fopen(fileName, "w");
    if(fptr == NULL)
    {
        printf("\nFile Creation Error!!!");
    }
    else
    {
        printf("\nFile Created Successfully!!!");
    }
    fclose(fptr);
}

void addDataToFile(char* fileName)
{
    FILE *fptr = fopen(fileName, "a");
    char data[100];
    printf("\nEnter Data to be Added to the File: ");
    scanf(" %[^\n]s",data);
    fprintf(fptr, "%s\n",data);
    fclose(fptr);
}

void readDataFromFile(char* fileName)
{
    FILE *fptr = fopen(fileName, "r");
    char ch;
    if(fptr == NULL)
    {
        printf("\nFile Not Found!!!");
    }
    else
    {
        printf("\nData in the File:\n");
        while((ch = fgetc(fptr)) != EOF)
        {
            printf("%c",ch);
        }
    }
    fclose(fptr);
}

void deleteDataFromFile(char* fileName)
{
    char data[50], temp[50];
    FILE *fptr1, *fptr2;
    printf("\nEnter Data to be Deleted from the File: ");
    scanf(" %[^\n]s",data);
    fptr1 = fopen(fileName, "r");
    fptr2 = fopen("temp.txt", "w");
    while(fscanf(fptr1, "%[^\n]s",temp) == 1)
    {
        if(strcmp(temp, data) != 0)
        {
            fprintf(fptr2, "%s\n", temp);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(fileName);
    rename("temp.txt", fileName);
    printf("\nData Deleted Successfully!!!");
}