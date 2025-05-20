//FormAI DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void print_error(int err_num) {
    switch(err_num) {
        case EACCES:
            printf("\nAccess denied!");
            break;
        case EBADF:
            printf("\nBad file descriptor!");
            break;
        case EFAULT:
            printf("\nBad address!");
            break;
        case EINVAL:
            printf("\nInvalid argument!");
            break;
        case EIO:
            printf("\nI/O error!");
            break;
        default:
            printf("\nUnknown error!");
    }
}

int main() {
    FILE *fp;
    char filename[] = "data.txt";
    int num;
    
    fp = fopen(filename, "r");
    
    if (fp == NULL) {
        print_error(errno);
        exit(EXIT_FAILURE);
    }
    
    fscanf(fp, "%d", &num);
    
    if (num < 0 || num > 10) {
        printf("\nInvalid input!");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    printf("\nValid input!");
    
    fclose(fp);
    return 0;
}