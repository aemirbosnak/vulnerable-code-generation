//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file
{
    char filename[50];
    char content[100];
    int size;
};

int main()
{
    int choice;
    int n = 0;
    struct file files[10];
    char filename[50];
    char content[100];
    int size;

    for(;;)
    {
        printf("\n*** Surreal C File System Simulation ***\n");
        printf("\n1. Create a new file");
        printf("\n2. Edit an existing file");
        printf("\n3. Delete a file");
        printf("\n4. Display all files");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the filename: ");
                scanf("%s", filename);
                printf("\nEnter the content: ");
                fflush(stdin);
                fgets(content, 100, stdin);
                printf("\nEnter the size (in bytes): ");
                scanf("%d", &size);
                strcpy(files[n].filename, filename);
                strcpy(files[n].content, content);
                files[n].size = size;
                printf("\nFile created successfully!");
                n++;
                break;
                
            case 2:
                printf("\nEnter the name of the file to edit: ");
                scanf("%s", filename);
                for(int i=0; i<n; i++)
                {
                    if(strcmp(files[i].filename, filename) == 0)
                    {
                        printf("\nEnter the new content: ");
                        fflush(stdin);
                        fgets(content, 100, stdin);
                        printf("\nEnter the new size: ");
                        scanf("%d", &size);
                        strcpy(files[i].content, content);
                        files[i].size = size;
                        printf("\nFile edited successfully!");
                        break;
                    }
                }
                break;
                
            case 3:
                printf("\nEnter the name of the file to delete: ");
                scanf("%s", filename);
                for(int i=0; i<n; i++)
                {
                    if(strcmp(files[i].filename, filename) == 0)
                    {
                        for(int j=i; j<n-1; j++)
                        {
                            strcpy(files[j].filename, files[j+1].filename);
                            strcpy(files[j].content, files[j+1].content);
                            files[j].size = files[j+1].size;
                        }
                        printf("\nFile deleted successfully!");
                        n--;
                        break;
                    }
                }
                break;
                
            case 4:
                if(n == 0)
                {
                    printf("\nNo files to display!");
                }
                else
                {
                    printf("\nList of files:");
                    for(int i=0; i<n; i++)
                    {
                        printf("\n%d. %s\t%d bytes", i+1, files[i].filename, files[i].size);
                    }
                }
                break;
                
            case 5:
                printf("\nExiting program...Goodbye!");
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice...Try again!");
        }
    }

    return 0;
}