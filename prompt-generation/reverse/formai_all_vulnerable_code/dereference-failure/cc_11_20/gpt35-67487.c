//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char * argv[])
{
    // check if user has entered enough arguments
    if (argc < 2) {
        printf("Please enter filename as an argument.\n");
        return 1;
    }
    
    // check if file exists
    if (access(argv[1], F_OK) == -1) {
        printf("File does not exist.\n");
        return 1;
    }
    
    // check if user has permission to read and write to the file
    if (access(argv[1], R_OK|W_OK) == -1) {
        printf("You do not have permission to read and write to this file.\n");
        return 1;
    }
    
    // open the file for reading and writing
    int file = open(argv[1], O_RDWR);
    if (file == -1)
    {
        perror("failed to open file");
        return 1;
    }
    
    // check if file is empty
    struct stat st;
    if (fstat(file, &st) == -1)
    {
        perror("failed to get file size");
        close(file);
        return 1;
    }

    if (st.st_size == 0)
    {
        printf("File is empty.\n");
        close(file);
        return 1;
    }
    
    // read file content into buffer
    char * buffer = malloc(st.st_size + 1);
    if (!buffer)
    {
        perror("failed to allocate memory for buffer");
        close(file);
        return 1;
    }

    int read_size = read(file, buffer, st.st_size);
    if (read_size == -1)
    {
        perror("failed to read file content");
        free(buffer);
        close(file);
        return 1;
    }
    
    buffer[read_size] = '\0';
    
    // search and replace operation
    char *search_term = "HELLO";
    char *replace_term = "WORLD";
    char *temp = NULL;
    char *new_content = NULL;
    
    int search_term_length = strlen(search_term);
    int replace_term_length = strlen(replace_term);
    
    // loop through buffer looking for search term
    for (int i = 0; i < read_size;)
    {
        if (strncmp(&buffer[i], search_term, search_term_length) == 0)
        {
            // allocate memory for temp and new content arrays
            temp = malloc((i + 1) * sizeof(char));
            new_content = malloc((read_size - i + replace_term_length) * sizeof(char));
            
            if (!temp || !new_content)
            {
                perror("failed to allocate memory for temp and/or new_content arrays");
                free(temp);
                free(new_content);
                free(buffer);
                close(file);
                return 1;
            }
            
            // copy data before search term into temp array
            strncpy(temp, buffer, i);
            temp[i] = '\0';
            
            // copy new content into new_content array
            strncpy(new_content, temp, i);
            strncpy(&new_content[i], replace_term, replace_term_length);
            strncpy(&new_content[i + replace_term_length], &buffer[i + search_term_length], read_size - i - search_term_length);
            new_content[read_size - search_term_length + replace_term_length] = '\0';
            
            // write new content to file and free memory
            lseek(file, 0, SEEK_SET);
            int write_size = write(file, new_content, st.st_size - search_term_length + replace_term_length);
            if (write_size == -1)
            {
                perror("failed to write new content to file");
                free(temp);
                free(new_content);
                free(buffer);
                close(file);
                return 1;
            }
            
            free(temp);
            free(new_content);
            free(buffer);
            close(file);
            return 0;
        }
        
        i++;
    }
    
    // if we reached here, the search term was not found in the file
    printf("Search term not found.\n");
    free(buffer);
    close(file);
    return 1;
}