//FormAI DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

/* Defining the structure of a file */
struct file
{
        char filename[50];
        int size;
        char content[100];
};

/* Defining the structure of a file system */
struct file_system
{
        struct file files[10];
        int num_files;
};

/* Function to create a new file */
void create_file(struct file_system* fs)
{
        if(fs->num_files >= 10) /* Return if the file system is full */
        {
                printf("File system is full!\n");
                return;
        }
        struct file new_file;
        printf("Enter file name:");
        scanf("%s", new_file.filename);
        printf("Enter file size:");
        scanf("%d", &new_file.size);
        printf("Enter file content:");
        scanf("%s", new_file.content);
        fs->files[fs->num_files] = new_file; /* Adding the new file to the file system */
        fs->num_files++;
}

/* Function to delete a file */
void delete_file(struct file_system* fs)
{
        if(fs->num_files == 0) /* Return if there are no files in the file system */
        {
                printf("File system is empty!\n");
                return;
        }
        char filename[50];
        printf("Enter file name to delete:");
        scanf("%s", filename);
        int index = -1;
        for(int i=0; i<fs->num_files; i++)
        {
                if(strcmp(fs->files[i].filename, filename) == 0) /* Finding the file with the given file name */
                {
                        index = i;
                        break;
                }
        }
        if(index == -1) /* Return if the file is not found */
        {
                printf("File not found!\n");
                return;
        }
        /* Deleting the file by shifting all files after it to the left */
        for(int i=index; i<fs->num_files-1; i++)
        {
                fs->files[i] = fs->files[i+1];
        }
        fs->num_files--;
        printf("File deleted successfully!\n");
}

/* Function to display all the files in the file system */
void display_files(struct file_system fs)
{
        if(fs.num_files == 0) /* Return if there are no files in the file system */
        {
                printf("File system is empty!\n");
                return;
        }
        printf("%-20s%-20s%-20s\n", "FileName", "FileSize", "Content");
        for(int i=0; i<fs.num_files; i++)
        {
                printf("%-20s%-20d%-20s\n", fs.files[i].filename, fs.files[i].size, fs.files[i].content);
        }
}

/* Main function */
int main()
{
        struct file_system fs;
        fs.num_files = 0;
        int choice;
        do
        {
                printf("\nFile System Menu\n");
                printf("1. Create file\n");
                printf("2. Delete file\n");
                printf("3. Display all files\n");
                printf("4. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1: create_file(&fs);
                                break;
                        case 2: delete_file(&fs);
                                break;
                        case 3: display_files(fs);
                                break;
                        case 4: printf("Exiting...\n");
                                break;
                        default: printf("Invalid choice!\n");
                }
        }while(choice != 4);
        return 0;
}