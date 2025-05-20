//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEASURES 10

typedef struct {
  char name[20];
  int age;
  double weight;
  double height;
  double heart_rate;
  double blood_pressure;
  double measures[MAX_MEASURES];
  time_t timestamp;
} FitnessTrackerRecord;

FitnessTrackerRecord records[100];

void add_record() {
  FitnessTrackerRecord new_record;

  printf("Enter your name: ");
  scanf("%s", new_record.name);

  printf("Enter your age: ");
  scanf("%d", &new_record.age);

  printf("Enter your weight: ");
  scanf("%lf", &new_record.weight);

  printf("Enter your height: ");
  scanf("%lf", &new_record.height);

  printf("Enter your heart rate: ");
  scanf("%lf", &new_record.heart_rate);

  printf("Enter your blood pressure: ");
  scanf("%lf", &new_record.blood_pressure);

  new_record.timestamp = time(NULL);

  for (int i = 0; i < MAX_MEASURES; i++) {
    printf("Enter your measure %d: ", i + 1);
    scanf("%lf", &new_record.measures[i]);
  }

  records[0] = new_record;
}

void print_records() {
  for (int i = 0; i < 100; i++) {
    if (records[i].name[0] != '\0') {
      printf("%s, %d, %.2lf, %.2lf, %.2lf, %.2lf, %.2lf, %.2lf, %s\n", records[i].name, records[i].age, records[i].weight, records[i].height, records[i].heart_rate, records[i].blood_pressure, records[i].measures[0], records[i].measures[1], records[i].timestamp);
    }
  }
}

int main() {
  add_record();
  print_records();

  return 0;
}