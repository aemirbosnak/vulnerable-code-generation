//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){

    char filename[20],choice;
    int fd1,fd2,n;
    struct stat status;

    printf("Enter the filename to be copied: ");
    scanf("%s",filename);

    if((fd1=open(filename,O_RDONLY))==-1){
        perror("Error opening file");
        exit(1);
    }

    if(fstat(fd1,&status) == -1){
        perror("Error getting file status");
        exit(1);
    } 

    printf("Enter the name of the copied file: ");
    scanf("%s",filename);

    if((fd2=creat(filename,status.st_mode))==-1){
        perror("Error creating file");
        exit(1);
    }
    
    char buffer[1024];
    while((n=read(fd1,buffer,sizeof(buffer)))>0){
        if(write(fd2,buffer,n)!=n){
            perror("Error writing to file");
            exit(1);
        }
    }

    printf("File copied successfully.\n");
    
    printf("Do you want to delete the original file? (y/n): ");
    scanf(" %c",&choice);

    if(choice == 'y'){
        if(remove(filename)==-1){
            perror("Error deleting file");
            exit(1);
        }
        printf("File deleted successfully.\n");
    }

    return 0;
}