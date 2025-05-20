//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

//Struct for data
struct data{
    char name[MAX];
    int age;
    float salary;
};

//Function for comparing salaries
int compareSalaries(const void *a, const void *b){
    float s1 = ((struct data*)a)->salary;
    float s2 = ((struct data*)b)->salary;
    return (s1 > s2) - (s1 < s2);
}

//Function for comparing ages
int compareAges(const void *a, const void *b){
    int age1 = ((struct data*)a)->age;
    int age2 = ((struct data*)b)->age;
    return (age1 > age2) - (age1 < age2);
}

//Function for comparing names
int compareNames(const void *a, const void *b){
    char n1[MAX] = " ";
    char n2[MAX] = " ";
    strcpy(n1, ((struct data*)a)->name);
    strcpy(n2, ((struct data*)b)->name);
    return strcmp(n1, n2);
}

//Function for sorting data
void sortData(struct data arr[], int n, int (*compare)(const void *, const void *)){
    qsort(arr, n, sizeof(struct data), compare);
}

//Main function
int main(){
    int n;
    scanf("%d", &n);
    struct data arr[n];
    for(int i=0; i<n; i++){
        scanf("%s %d %f", arr[i].name, &arr[i].age, &arr[i].salary);
    }
    int choice;
    printf("Enter the sorting criteria:\n1. Sort by name\n2. Sort by age\n3. Sort by salary\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            sortData(arr, n, compareNames);
            break;
        case 2:
            sortData(arr, n, compareAges);
            break;
        case 3:
            sortData(arr, n, compareSalaries);
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    printf("Sorted data:\n");
    for(int i=0; i<n; i++){
        printf("%s %d %f\n", arr[i].name, arr[i].age, arr[i].salary);
    }
    return 0;
}