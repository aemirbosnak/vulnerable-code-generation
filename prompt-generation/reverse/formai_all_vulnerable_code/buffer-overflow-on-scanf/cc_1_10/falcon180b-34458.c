//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_LENGTH 1024
#define MAX_LINE_LENGTH 80
#define MAX_WHITE_SPACE 10

// Function to remove white spaces from the string
void remove_spaces(char* str)
{
    int i = 0;
    int j = 0;
    while(str[i])
    {
        // Check if the character is a white space
        if(isspace(str[i]))
        {
            // Shift all characters after the white space to the left
            while(str[i])
            {
                str[i] = str[i+1];
                i++;
            }
        }
        else
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

// Function to check if the string is a virus
bool is_virus(char* str)
{
    remove_spaces(str);
    if(strcmp(str, "virus") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to scan the file for viruses
void scan_file(FILE* file)
{
    char line[MAX_LENGTH];
    char str[MAX_LINE_LENGTH];
    int i = 0;
    int j = 0;
    while(fgets(line, MAX_LENGTH, file)!= NULL)
    {
        if(strlen(line) > MAX_LINE_LENGTH)
        {
            printf("Line too long!\n");
            continue;
        }
        // Remove white spaces from the line
        remove_spaces(line);
        // Check if the line contains a virus
        if(is_virus(line))
        {
            printf("Virus found in line %d:\n%s\n", i+1, line);
            return;
        }
        i++;
    }
}

// Function to check if the file exists
bool file_exists(char* filename)
{
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        return false;
    }
    else
    {
        fclose(file);
        return true;
    }
}

int main()
{
    char filename[MAX_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    if(!file_exists(filename))
    {
        printf("File not found!\n");
        return 1;
    }
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Could not open file!\n");
        return 1;
    }
    scan_file(file);
    fclose(file);
    return 0;
}