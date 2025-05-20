//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_WORKOUTS 5

typedef struct{
    char name[20];
    int age;
    float height;
    float weight;
    char gender[10];
} User;

typedef struct{
    char name[20];
    int duration;
    float calories;
} Workout;

typedef struct{
    int user_id;
    int workout_id;
    char date[12];
} Entry;

User users[MAX_USERS];
Workout workouts[MAX_WORKOUTS];
Entry entries[MAX_USERS * MAX_WORKOUTS]; 

int num_users = 0;
int num_workouts = 0;
int num_entries = 0;

void print_menu(){
    printf("\n\nFitness Tracker\n\n");
    printf("1. Add User\n");
    printf("2. Add Workout\n");
    printf("3. Add Entry\n");
    printf("4. View User Stats\n");
    printf("5. View All Entries\n");
    printf("6. Quit\n\n");
}

void add_user(){
    User user;
    printf("\nEnter User Details:\n");
    printf("Name: ");
    scanf("%s", user.name);
    printf("Age: ");
    scanf("%d", &user.age);
    printf("Height: ");
    scanf("%f", &user.height);
    printf("Weight: ");
    scanf("%f", &user.weight);
    printf("Gender: ");
    scanf("%s", user.gender);
    users[num_users++] = user;
    printf("\nUser Added Successfully\n");
}

void add_workout(){
    Workout workout;
    printf("\nEnter Workout Details:\n");
    printf("Name: ");
    scanf("%s", workout.name);
    printf("Duration: ");
    scanf("%d", &workout.duration);
    printf("Calories Burned: ");
    scanf("%f", &workout.calories);
    workouts[num_workouts++] = workout;
    printf("\nWorkout Added Successfully\n");
}

void add_entry(){
    Entry entry;
    printf("\nEnter Entry Details:\n");
    printf("User ID: ");
    scanf("%d", &entry.user_id);
    printf("Workout ID: ");
    scanf("%d", &entry.workout_id);
    printf("Date (YYYY/MM/DD): ");
    scanf("%s", entry.date);
    entries[num_entries++] = entry;
    printf("\nEntry Added Successfully\n");
}

void view_user_stats(){
    printf("\nEnter User ID: ");
    int user_id, i, j;
    scanf("%d", &user_id);
    for(i=0;i<num_users;i++){
        if(users[i].age == user_id){
            printf("\nName: %s\n", users[i].name);
            printf("Age: %d\n", users[i].age);
            printf("Height: %.2f\n", users[i].height);
            printf("Weight: %.2f\n", users[i].weight);
            printf("Gender: %s\n\n", users[i].gender);
            float total_calories = 0;
            printf("Entries:\n\n");
            for(j=0;j<num_entries;j++){
                if(entries[j].user_id == user_id){
                    printf("Date: %s\n", entries[j].date);
                    printf("Workout: %s\n", workouts[entries[j].workout_id].name);
                    printf("Calories Burned: %.2f\n\n", workouts[entries[j].workout_id].calories);
                    total_calories += workouts[entries[j].workout_id].calories;
                }
            }
            printf("Total Calories Burned: %.2f\n", total_calories);
            return;
        }
    }
    printf("\nUser Not Found\n");
}

void view_all_entries(){
    printf("\nAll Entries:\n\n");
    int i;
    for(i=0;i<num_entries;i++){
        printf("Date: %s\n", entries[i].date);
        printf("User: %s\n", users[entries[i].user_id].name);
        printf("Workout: %s\n", workouts[entries[i].workout_id].name);
        printf("Calories Burned: %.2f\n\n", workouts[entries[i].workout_id].calories);
    }
}

int main(){

    int ch=0;

    while(ch!=6){

        print_menu();
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                add_user();
                break;

            case 2:
                add_workout();
                break;

            case 3:
                add_entry();
                break;

            case 4:
                view_user_stats();
                break;

            case 5:
                view_all_entries();
                break;

            case 6:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }

    return 0;
}