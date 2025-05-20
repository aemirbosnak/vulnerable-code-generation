//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include<stdio.h>
#include<string.h>

typedef struct{
    int day;
    int month;
    int year;
} Date;

typedef struct{
    char name[20];
    float height;
    float weight;
    Date dob; 
} Person;

typedef struct{
    int steps;
    float distance;
    float calories;
    Date date;
} Workout;

Person createPerson(){
    Person p;
    printf("Enter name: ");
    scanf("%s", p.name);
    printf("Enter height in meters: ");
    scanf("%f", &p.height);
    printf("Enter weight in kgs: ");
    scanf("%f", &p.weight);
    printf("Enter date of birth (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &p.dob.day, &p.dob.month, &p.dob.year);
    return p;
}

void displayPerson(Person p){
    printf("\nName : %s\n",p.name);
    printf("Height : %.2f m\n",p.height);
    printf("Weight : %.2f kg\n",p.weight);
    printf("DOB : %d-%d-%d\n", p.dob.day, p.dob.month, p.dob.year);
}

Workout createWorkout(Date date){
    Workout w;
    w.date = date;
    printf("Enter steps taken: ");
    scanf("%d",&w.steps);
    printf("Enter distance traveled in kms: ");
    scanf("%f",&w.distance);
    printf("Enter calories burned: ");
    scanf("%f",&w.calories);
    return w;
}

void displayWorkout(Workout w){
    printf("\nDate : %d-%d-%d\n",w.date.day, w.date.month, w.date.year);
    printf("Steps : %d\n",w.steps);
    printf("Distance : %.2f km\n",w.distance);
    printf("Calories burned : %.2f kcal\n",w.calories);
}

int main(){
    Person p = createPerson();
    int option = 0;
    do{
        printf("\nPlease select an option:\n");
        printf("1. Add workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        scanf("%d",&option);

        switch(option){
            case 1:{
                Date date;
                printf("\nPlease enter workout date (dd-mm-yyyy): ");
                scanf("%d-%d-%d",&date.day,&date.month,&date.year);
                Workout w = createWorkout(date);
                // write to file
                FILE *fptr;
                fptr = fopen("workouts.txt", "a");
                if(fptr == NULL){
                    printf("\nError opening file!");
                    break;
                }
                fprintf(fptr,"%d-%d-%d,%d,%.2f,%.2f\n",w.date.day,w.date.month,w.date.year,w.steps,w.distance,w.calories);
                fclose(fptr);
                printf("\nWorkout added successfully!");
                break;
            }
            case 2:{
                FILE *fptr;
                fptr = fopen("workouts.txt", "r");
                if(fptr == NULL){
                    printf("\nError opening file!");
                    break;
                }
                printf("\nWORKOUT HISTORY : \n");
                printf("--------------------------------------------------------------\n");
                printf("DATE\t\tSTEPS\tDISTANCE\tCALORIES BURNED\n");
                printf("--------------------------------------------------------------\n");
                char line[50];
                while (fgets(line, 50, fptr) != NULL) {
                    printf("%s", line);
                }
                fclose(fptr);
                break;
            }
            case 3:{
                printf("\nThank you for using the fitness tracker!\n");
                break;
            }
            default:
                printf("\nInvalid option\n");
                break;
        }
    }while(option!=3);
    return 0;
}