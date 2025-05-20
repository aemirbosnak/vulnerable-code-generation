//FormAI DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

#define MAX_MESSAGE_LEN 1024

int main(){
    int fd, data_size, i;
    void *addr;
    char input[MAX_MESSAGE_LEN];
    pid_t child_pid;

    //Create the shared memory segment
    if ( (fd = shm_open("/sample_memory", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1 ){
        perror("Failed to open shared memory segment");
        exit(1);
    }

    //Resize the shared memory segment to the size of a message
    data_size = sizeof(input);
    if ( ftruncate(fd, data_size) == -1 ){
        perror("Failed to resize shared memory segment");
        exit(1);
    }

    //Map the shared memory segment to the process's address space
    addr = mmap(NULL, data_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if ( addr == MAP_FAILED ){
        perror("Failed to map shared memory segment");
        exit(1);
    }

    //Fork a child process
    child_pid = fork();

    if ( child_pid == -1 ){
        perror("Failed to fork child process");
        exit(1);
    }

    //Child process: Read message from shared memory segment and print it
    if ( child_pid == 0 ){
        while(1){
            printf("\n[Child Process] Reading message: %s", (char *)addr);
            sleep(1);
        }
    }

    //Parent process: Write message to shared memory segment and wait for child to exit
    else{
        while(1){
            printf("\n[Parent Process] Enter message: ");
            fgets(input, MAX_MESSAGE_LEN, stdin);
            if ( input[strlen(input)-1] == '\n' ){
                input[strlen(input)-1] = '\0';
            }
            snprintf((char *)addr, MAX_MESSAGE_LEN, "%s", input);
            sleep(1);
        }
        wait(NULL);
    }

    //Unmap the shared memory segment and unlink it
    if ( munmap(addr, data_size) == -1 ){
        perror("Failed to unmap shared memory segment");
        exit(1);
    }
    if ( shm_unlink("/sample_memory") == -1 ){
        perror("Failed to unlink shared memory segment");
        exit(1);
    }

    return 0;
}