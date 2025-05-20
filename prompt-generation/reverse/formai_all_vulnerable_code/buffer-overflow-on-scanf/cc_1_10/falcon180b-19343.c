//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char file_name[50];
    printf("Enter file name: ");
    scanf("%s", file_name);

    int file_id = open(file_name, O_RDONLY);
    if(file_id == -1) {
        printf("Error: File not found\n");
        return 0;
    }
    struct stat file_stat;
    fstat(file_id, &file_stat);
    int file_size = file_stat.st_size;
    char *file_buffer = (char *)malloc(file_size);
    if(file_buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        return 0;
    }
    int bytes_read = read(file_id, file_buffer, file_size);
    if(bytes_read!= file_size) {
        printf("Error: File read failed\n");
        return 0;
    }
    close(file_id);

    char *virus_name = "virus";
    int virus_length = strlen(virus_name);
    int virus_found = 0;

    for(int i=0; i<file_size; i++) {
        if(file_buffer[i] == virus_name[0]) {
            int j;
            for(j=0; j<virus_length; j++) {
                if(file_buffer[i+j]!= virus_name[j]) {
                    break;
                }
            }
            if(j == virus_length) {
                virus_found = 1;
                break;
            }
        }
    }

    if(virus_found) {
        printf("File contains a virus\n");
    } else {
        printf("File is clean\n");
    }

    free(file_buffer);
    return 0;
}