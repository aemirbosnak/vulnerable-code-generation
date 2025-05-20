//FormAI DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

//Define a struct to represent a student record
typedef struct {
    int rollNo;
    char name[20];
    float marks;
}StudentRecord;

//Function to read the student records from a file
StudentRecord* readRecords(char* filename, int* n) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Unable to read file '%s'\n", filename);
        exit(1);
    }
    //Count the number of records in the file
    char ch;
    *n = 0;
    while((ch = fgetc(fp)) != EOF) {
        if(ch == '\n') (*n)++;
    }
    rewind(fp); //Move the file pointer to the beginning of the file
    
    //Allocate memory to store the records
    StudentRecord* records = (StudentRecord*) malloc(*n * sizeof(StudentRecord));
    if(records == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }
    //Read the records from the file
    for(int i=0; i<*n; i++) {
        fscanf(fp, "%d,%[^,],%f", &records[i].rollNo, records[i].name, &records[i].marks);
    }
    fclose(fp); //Close the file
    return records;
}

//Function to find the top performers
void findTopPerformers(StudentRecord* records, int n, int k) {
    //Sort the records based on marks in descending order using bubble sort
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(records[j].marks < records[j+1].marks) {
                //Swap records[j] and records[j+1]
                StudentRecord temp = records[j];
                records[j] = records[j+1];
                records[j+1] = temp;
            }
        }
    }
    //Print the top k performers
    printf("Top %d Performers:\n", k);
    for(int i=0; i<k; i++) {
        printf("%d\t%s\t%f\n", records[i].rollNo, records[i].name, records[i].marks);
    }
}

int main() {
    char filename[20];
    int n, k;
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the value of k (number of top performers to be displayed): ");
    scanf("%d", &k);
    
    //Read the student records from the file
    StudentRecord* records = readRecords(filename, &n);
    //Find the top performers
    findTopPerformers(records, n, k);
    //Free the allocated memory
    free(records);
    
    return 0;
}