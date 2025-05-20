//Falcon-180B DATASET v1.0 Category: File handling ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 100

typedef struct{
    char name[20];
    int age;
    float height;
}Person;

void read_data(FILE* fptr, Person arr[], int n){
    int i=0;
    while(fscanf(fptr, "%s %d %f", arr[i].name, &arr[i].age, &arr[i].height)!=EOF){
        i++;
    }
    rewind(fptr);
}

void write_data(FILE* fptr, Person arr[], int n){
    int i=0;
    while(i<n){
        fprintf(fptr, "%s %d %f\n", arr[i].name, arr[i].age, arr[i].height);
        i++;
    }
}

void sort_data(Person arr[], int n, char* key){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(arr[i].name, arr[j].name)>0){
                Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void search_data(FILE* fptr, Person arr[], int n, char* key){
    int found=0;
    char ch;
    Person temp;
    while(fscanf(fptr, "%s %d %f", temp.name, &temp.age, &temp.height)!=EOF){
        if(strcmp(temp.name, key)==0){
            found=1;
            printf("\nName: %s\nAge: %d\nHeight: %f\n", temp.name, temp.age, temp.height);
        }
    }
    if(found==0){
        printf("\nRecord not found!");
    }
    rewind(fptr);
}

int main(){
    FILE* fptr;
    char filename[20];
    int choice, n=0;
    Person arr[MAX_SIZE];

    printf("\nEnter the file name: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r+");

    if(fptr==NULL){
        printf("\nFile not found!");
        exit(0);
    }

    printf("\nEnter 1 to read data\nEnter 2 to write data\nEnter 3 to sort data\nEnter 4 to search data\nEnter 5 to exit\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("\nEnter the number of records: ");
            scanf("%d", &n);
            read_data(fptr, arr, n);
            printf("\nData read successfully!\n");
            break;
        case 2:
            printf("\nEnter the number of records: ");
            scanf("%d", &n);
            write_data(fptr, arr, n);
            printf("\nData written successfully!\n");
            break;
        case 3:
            sort_data(arr, n, "name");
            printf("\nData sorted successfully!\n");
            break;
        case 4:
            printf("\nEnter the name to search: ");
            scanf("%s", filename);
            search_data(fptr, arr, n, filename);
            break;
        case 5:
            printf("\nExiting program!");
            break;
        default:
            printf("\nInvalid choice!");
    }

    fclose(fptr);
    return 0;
}