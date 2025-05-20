//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a student
struct student {
    int id;
    char name[50];
    float marks;
};

// A function to swap two student
void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

// A function to perform bubble sort on an array of students
void bubbleSort(struct student arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].marks > arr[j+1].marks) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// A function to input details of students from file
void readData(struct student arr[], int n, char* fileName) {
    FILE* fptr;
    fptr = fopen(fileName, "r");
    if(fptr == NULL) {
        printf("Unable to open file!");
        exit(1);
    }
    for(int i=0; i<n; i++) {
        fscanf(fptr, "%d,%[^,],%f", &arr[i].id, arr[i].name, &arr[i].marks);
    }
    fclose(fptr);
}

// A function to output details of students to file
void writeData(struct student arr[], int n, char* fileName) {
    FILE* fptr;
    fptr = fopen(fileName, "w");
    if(fptr == NULL) {
        printf("Unable to open file!");
        exit(1);
    }
    for(int i=0; i<n; i++) {
        fprintf(fptr, "%d,%s,%f\n", arr[i].id, arr[i].name, arr[i].marks);
    }
    fclose(fptr);
}

int main() {
    int n = 5; // Number of students
    struct student arr[n]; // Array of students
    
    // Input details of students from file
    readData(arr, n, "input.csv");

    // Sort the array of students by marks using bubble sort
    bubbleSort(arr, n);

    // Output details of sorted students to file
    writeData(arr, n, "output.csv");

    printf("Sorting of students is done. Check the output.csv file for the result.");

    return 0;
}