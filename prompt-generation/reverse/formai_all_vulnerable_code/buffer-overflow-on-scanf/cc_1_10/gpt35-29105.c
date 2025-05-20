//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
    char name[256];
    int size;
};

int main()
{
    int n = 0, total_size = 0, max_size = 0;
    char buffer[256], temp[256];
    struct file *files = NULL;

    printf("Enter the number of files: ");
    scanf("%d", &n);
    getchar(); // to consume the newline character left by scanf

    // Dynamically allocating memory for the files array
    files = (struct file*)malloc(n * sizeof(struct file));

    // Reading filenames and sizes from user
    for(int i = 0; i < n; i++)
    {
        printf("Enter filename %d: ", i+1);
        fgets(buffer, 256, stdin);
        // Removing newline character from the end of filename
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(files[i].name, buffer);

        printf("Enter size of %s (in bytes): ", files[i].name);
        scanf("%d", &files[i].size);
        total_size += files[i].size;
        max_size = (max_size < files[i].size) ? files[i].size : max_size;

        // Consuming the newline character left by scanf
        getchar(); 
    }

    // Displaying the file details
    printf("\n%-30s %10s\n", "Filename", "Size (bytes)");
    printf("----------------------------------------------\n");
    for(int i = 0; i < n; i++)
        printf("%-30s %10d\n", files[i].name, files[i].size);
    printf("\nTotal disk space used: %d bytes\n", total_size);
    printf("Largest file size: %d bytes\n\n", max_size);

    // Sorting the files array based on size (in descending order)
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(files[j].size > files[i].size)
            {
                // swapping files[i] and files[j]
                strcpy(temp, files[i].name);
                int size = files[i].size;
                strcpy(files[i].name, files[j].name);
                files[i].size = files[j].size;
                strcpy(files[j].name, temp);
                files[j].size = size;
            }
        }
    }

    // Displaying the top 5 largest files
    printf("Top 5 largest files:\n");
    printf("%-30s %10s\n", "Filename", "Size (bytes)");
    printf("----------------------------------------------\n");
    for(int i = 0; i < 5 && i < n; i++)
        printf("%-30s %10d\n", files[i].name, files[i].size);

    free(files);
    return 0;
}