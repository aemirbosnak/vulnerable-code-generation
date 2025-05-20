//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[30];
  int age;
  float height;
  float weight;
} Person;

typedef struct {
  Person person_info;
  float bmi;
  float target_weight;
  int steps;
} Fitness;

void display_menu() {
  printf("Fitness Tracker\n");
  printf("================\n");
  printf("1. Add a person\n");
  printf("2. Calculate BMI and target weight\n");
  printf("3. Log steps\n");
  printf("4. Quit\n");
}

void add_person(Fitness *f) {
  printf("Enter name: ");
  scanf("%s", f->person_info.name);
  printf("Enter age: ");
  scanf("%d", &f->person_info.age);
  printf("Enter height in meters: ");
  scanf("%f", &f->person_info.height);
  printf("Enter weight in kg: ");
  scanf("%f", &f->person_info.weight);
}

void calculate_bmi(Fitness *f) {
  f->bmi = f->person_info.weight / (f->person_info.height * f->person_info.height);
  printf("BMI: %.2f\n", f->bmi);

  if (f->bmi < 18.5){
      f->target_weight = ((18.6 / f->bmi) * f->person_info.height * f->person_info.height);
      printf("Target weight: %.2f\n", f->target_weight);
  } else if (f->bmi < 25) {
      printf("You are already at a healthy weight!\n");
  } else {
      f->target_weight = ((24.9 / f->bmi) * f->person_info.height * f->person_info.height);
      printf("Target weight: %.2f\n", f->target_weight);
  }
}

void log_steps(Fitness *f) {
  printf("Enter number of steps: ");
  scanf("%d", &f->steps);
  printf("Steps logged successfully!\n");
}

int main() {
  Fitness f;
  int choice = -1;

  while (choice != 4) {
    display_menu();
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_person(&f);
        break;
      case 2:
        calculate_bmi(&f);
        break;
      case 3:
        log_steps(&f);
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}