//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing file data
struct file
{
    char name[100];      // Name of the file
    char extension[5];   // Extension of the file
    char data[1000];     // Data of the file
    int size;            // Size of the file
};

// Function to create file structure
struct file create_file(char name[], char extension[], char data[], int size)
{
    struct file f;
    strcpy(f.name, name);
    strcpy(f.extension, extension);
    strcpy(f.data, data);
    f.size = size;
    return f;
}

// Function to write file to disk
int write_file(struct file f)
{
    FILE *fp;
    char fname[105];
    sprintf(fname, "%s.%s", f.name, f.extension);
    fp = fopen(fname, "w");
    if(fp == NULL)
    {
        return 0;
    }
    fwrite(f.data, sizeof(char), f.size, fp);
    fclose(fp);
    return 1;
}

// Function to read file from disk
struct file read_file(char name[], char extension[])
{
    FILE *fp;
    char fname[105];
    sprintf(fname, "%s.%s", name, extension);
    fp = fopen(fname, "r");
    if(fp == NULL)
    {
        struct file temp;
        strcpy(temp.name, "");
        return temp;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    struct file f = create_file(name, extension, "", size);
    fread(f.data, sizeof(char), size, fp);
    fclose(fp);
    return f;
}

// Function to recover lost files
void recover_files()
{
    int i;
    char ch, name[100], extension[5], data[1000];
    printf("Enter name of file to recover: ");
    scanf("%s", name);
    printf("Enter extension of file to recover: ");
    scanf("%s", extension);
    struct file f = read_file(name, extension);
    if(strcmp(f.name, "") == 0)
    {
        printf("File not found!\n");
        return;
    }
    printf("File found!\n");
    printf("Do you want to recover the file? (Y/N) ");
    scanf(" %c", &ch);
    if(ch == 'Y' || ch == 'y')
    {
        int success = write_file(f);
        if(success)
        {
            printf("File recovered successfully!\n");
            return;
        }
        else
        {
            printf("Failed to recover file!\n");
        }
    }
    else
    {
        printf("File not recovered!\n");
    }
}

// Main function
int main()
{
    char ch;
    do
    {
        recover_files();
        printf("Do you want to recover more files? (Y/N) ");
        scanf(" %c", &ch);
    }while(ch == 'Y' || ch == 'y');
    return 0;
}