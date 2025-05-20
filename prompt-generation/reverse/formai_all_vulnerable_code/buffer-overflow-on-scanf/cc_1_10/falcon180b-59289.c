//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 100

typedef struct{
    char name[MAX_SIZE];
    int age;
    float height;
}Person;

void addPerson(Person* people, int num){
    printf("Enter name: ");
    scanf("%s", people[num].name);
    printf("Enter age: ");
    scanf("%d", &people[num].age);
    printf("Enter height: ");
    scanf("%f", &people[num].height);
}

void displayPeople(Person* people, int num){
    printf("Name: %s\n", people[num].name);
    printf("Age: %d\n", people[num].age);
    printf("Height: %.2f\n\n", people[num].height);
}

int main(){
    Person people[MAX_SIZE];
    int numPeople = 0;

    while(1){
        printf("Enter 1 to add a person\n");
        printf("Enter 2 to display people\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &numPeople);

        switch(numPeople){
            case 1:
                addPerson(people, numPeople);
                numPeople++;
                break;
            case 2:
                for(int i=0; i<numPeople; i++){
                    displayPeople(people, i);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}