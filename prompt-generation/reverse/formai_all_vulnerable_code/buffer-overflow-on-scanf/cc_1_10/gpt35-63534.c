//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define CHUNK_SIZE 1024

void backup_file(char* filename, int backup_number);
void copy_file(int fd_in, int fd_out);

int main(int argc, char **argv) {
    int fd[MAX_FILES];
    int num_files = 0;
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    sprintf(output_filename, "backup_%d", num_files);
    
    printf("Enter name of file to backup: ");
    scanf("%s", input_filename);
    
    fd[num_files] = open(input_filename, O_RDONLY);
    if (fd[num_files] == -1) {
        printf("Error opening file!\n");
        return 1;
    }
    
    backup_file(output_filename, num_files);
    num_files++;
    
    while(num_files < MAX_FILES) {
        char answer[4];
        printf("Backup another file? (y/n): ");
        scanf("%s", answer);
        if (answer[0] == 'y' || answer[0] == 'Y') {
            printf("Enter name of file to backup: ");
            scanf("%s", input_filename);
            sprintf(output_filename, "backup_%d", num_files);
            
            fd[num_files] = open(input_filename, O_RDONLY);
            if (fd[num_files] == -1) {
                printf("Error opening file!\n");
                return 1;
            }
            
            backup_file(output_filename, num_files);
            num_files++;
        } else {
            break;
        }
    }
    
    printf("Backup complete.\n");
    return 0;
}

void backup_file(char* filename, int backup_number) {
    char buffer[CHUNK_SIZE];
    int fd_in, fd_out;
    sprintf(filename, "backup_%d", backup_number);
    fd_out = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_out == -1) {
        printf("Error creating backup file!\n");
        return;
    }
    fd_in = open(filename, O_RDONLY);
    if (fd_in == -1) {
        printf("Error opening original file!\n");
        return;
    }
    copy_file(fd_in, fd_out);
}

void copy_file(int fd_in, int fd_out) {
    char buffer[CHUNK_SIZE];
    ssize_t num_read = 0;
    while ((num_read = read(fd_in, buffer, CHUNK_SIZE)) > 0) {
        if (write(fd_out, buffer, num_read) != num_read) {
            printf("Error writing to backup file!\n");
            return;
        }
    }
    if (num_read == -1) {
        printf("Error reading original file!\n");
        return;
    }
    close(fd_in);
    close(fd_out);
}