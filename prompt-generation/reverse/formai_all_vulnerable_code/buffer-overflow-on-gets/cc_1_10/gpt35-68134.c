//FormAI DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int num, sum=0, count=0;
    float avg;
    char name[50];
    
    //get filename from user
    printf("Enter filename: ");
    gets(name);
    
    //open file in read mode
    fp = fopen(name, "r");
    
    //file open error handling
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    //read integers from file and calculate sum
    while(fscanf(fp, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    
    //close file
    fclose(fp);
    
    //calculate avg
    if(count != 0) {
        avg = (float)sum / count;
    } else {
        avg = 0;
    }
    
    //open same file in write mode
    fp = fopen(name, "w");
    
    //file open error handling
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    //write sum and avg to file
    fprintf(fp, "Sum=%.2d\nAvg=%.2f\n", sum, avg);
    
    //close file
    fclose(fp);
    
    return 0;
}