//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recoverData(char* filename)
{
    int i;
    char ch;
    FILE *fp, *fp1;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\nFile does not exist.\n");
        return;
    }
    fp1 = fopen("recovered_data.txt", "w");
    while(1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, fp1);
    }
    printf("\nData recovered successfully.\n");
    fclose(fp);
    fclose(fp1);
}

void renameFile(char* oldName, char* newName)
{
    if (rename(oldName, newName) == 0)
    {
        printf("\nFile renamed successfully.\n");
    }
    else
    {
        printf("\nError renaming the file.");
    }
}

void copyFile(char* oldLocation, char* newLocation)
{
    char* buffer = (char*)malloc(1048576);
    FILE *f1, *f2;
    size_t n;
    f1 = fopen(oldLocation, "rb");
    if (f1 == NULL)
    {
        printf("\nFile does not exist.\n");
        return;
    }
    f2 = fopen(newLocation, "wb");
    if (f2 == NULL)
    {
        printf("\nCould not create destination file.\n");
        return;
    }
    while ((n = fread(buffer, 1, 1048576, f1)) != 0)
    {
        fwrite(buffer, 1, n, f2);
    }
    printf("\nFile copied successfully.\n");
    fclose(f1);
    fclose(f2);
}

void deleteData(char* filename)
{
    int i;
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("\nCould not delete the data.\n");
        return;
    }
    fputs("", fp);
    printf("\nData successfully deleted.\n");
    fclose(fp);
}

void addData(char* filename)
{
    int i;
    char data[256];
    char ch;
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("\nCould not add data to the file.\n");
        return;
    }
    printf("\nEnter the data that you want to add to the file: ");
    gets(data);
    fputs(data, fp);
    printf("\nData added successfully.\n");
    fclose(fp);
}

int main()
{
    int choice;
    char filename[256];
    char newfilename[256];
    char oldLocation[256];
    char newLocation[256];
    while(1)
    {
        printf("\n1. Copy a file\n2. Rename a file\n3. Delete the data of a file\n4. Add data to a file\n5. Recover data from a file\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the source file location: ");
                scanf("%s", oldLocation);
                printf("\nEnter the destination file location: ");
                scanf("%s", newLocation);
                copyFile(oldLocation, newLocation);
                break;
            case 2:
                printf("\nEnter the name of the file that you want to rename: ");
                scanf("%s", filename);
                printf("\nEnter the new filename: ");
                scanf("%s", newfilename);
                renameFile(filename, newfilename);
                break;
            case 3:
                printf("\nEnter the name of the file that you want to delete the data from: ");
                scanf("%s", filename);
                deleteData(filename);
                break;
            case 4:
                printf("\nEnter the name of the file that you want to add data to: ");
                scanf("%s", filename);
                addData(filename);
                break;
            case 5:
                printf("\nEnter the name of the file that you want to recover data from: ");
                scanf("%s", filename);
                recoverData(filename);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}