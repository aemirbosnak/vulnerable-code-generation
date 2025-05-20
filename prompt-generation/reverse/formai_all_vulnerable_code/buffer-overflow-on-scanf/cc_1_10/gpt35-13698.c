//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PATH 260
#define MAX_FILESIZE 1048576 // Maximum file size in bytes: 1MB

char infected_files[100][MAX_PATH];
int num_infected_files = 0;

void scan_file(char *filepath);

int main()
{
    printf("\nC Antivirus Scanner\n\n");
    printf("Enter the directory where you want to start the scan (e.g. C:\\Windows): ");
    char start_dir[MAX_PATH];
    scanf("%s", start_dir);
    
    printf("\nStarting scan...\n\n");
    
    scan_file(start_dir);
    
    int i;
    if(num_infected_files == 0)
    {
        printf("No infected files found!\n");
    }
    else
    {
        printf("Infected files found: \n");
        for(i=0; i<num_infected_files; i++)
        {
            printf("%s\n", infected_files[i]);
        }
    }
    
    return 0;
}

void scan_file(char *filepath)
{
    FILE *file;
    char buffer[MAX_FILESIZE];
    
    file = fopen(filepath, "rb");
    if(file == NULL)
    {
        return;
    }
    
    int file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(buffer, sizeof(char), file_size, file);
    
    fclose(file);
    
    int i;
    for(i=0; i<file_size; i++)
    {
        if(buffer[i]=='V' && buffer[i+1]=='I' && buffer[i+2]=='R' && buffer[i+3]=='U' && buffer[i+4]=='S')
        {
            strcpy(infected_files[num_infected_files], filepath);
            num_infected_files++;
            break;
        }
    }
    
    return;
}