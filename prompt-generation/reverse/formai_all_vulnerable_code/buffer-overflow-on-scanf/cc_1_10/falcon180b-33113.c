//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_USER_NUM 10
#define MAX_EXCERCISE_NUM 20
#define MAX_DAY_NUM 30

typedef struct {
    char name[20];
    int age;
} User;

typedef struct {
    char name[50];
    int calories;
} Exercise;

typedef struct {
    int year;
    int month;
    int day;
} Date;

User users[MAX_USER_NUM];
Exercise exercises[MAX_EXCERCISE_NUM];
Date dates[MAX_DAY_NUM];

int user_num = 0;
int exercise_num = 0;
int day_num = 0;

void add_user() {
    user_num++;
    printf("Enter user name: ");
    scanf("%s", users[user_num-1].name);
    printf("Enter user age: ");
    scanf("%d", &users[user_num-1].age);
}

void add_exercise() {
    exercise_num++;
    printf("Enter exercise name: ");
    scanf("%s", exercises[exercise_num-1].name);
    printf("Enter exercise calories: ");
    scanf("%d", &exercises[exercise_num-1].calories);
}

void add_day() {
    day_num++;
    printf("Enter day date (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &dates[day_num-1].year, &dates[day_num-1].month, &dates[day_num-1].day);
}

void print_users() {
    printf("User list:\n");
    for(int i=0; i<user_num; i++) {
        printf("%s, %d years old\n", users[i].name, users[i].age);
    }
}

void print_exercises() {
    printf("Exercise list:\n");
    for(int i=0; i<exercise_num; i++) {
        printf("%s, %d calories\n", exercises[i].name, exercises[i].calories);
    }
}

void print_days() {
    printf("Day list:\n");
    for(int i=0; i<day_num; i++) {
        printf("%d-%d-%d\n", dates[i].year, dates[i].month, dates[i].day);
    }
}

int main() {
    srand(time(NULL));
    add_user();
    add_exercise();
    add_day();
    print_users();
    print_exercises();
    print_days();
    return 0;
}