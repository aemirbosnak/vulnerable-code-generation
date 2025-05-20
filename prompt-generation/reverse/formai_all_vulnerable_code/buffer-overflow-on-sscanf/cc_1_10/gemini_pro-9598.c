//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a fitness tracker entry
typedef struct FitnessTrackerEntry {
  time_t timestamp;
  int steps;
  int caloriesBurned;
  int distanceTraveled;
} FitnessTrackerEntry;

// Create a new fitness tracker entry
FitnessTrackerEntry* createFitnessTrackerEntry(time_t timestamp, int steps, int caloriesBurned, int distanceTraveled) {
  FitnessTrackerEntry* entry = malloc(sizeof(FitnessTrackerEntry));
  entry->timestamp = timestamp;
  entry->steps = steps;
  entry->caloriesBurned = caloriesBurned;
  entry->distanceTraveled = distanceTraveled;
  return entry;
}

// Add a fitness tracker entry to a decentralized database
void addFitnessTrackerEntryToDatabase(FitnessTrackerEntry* entry) {
  // In a decentralized system, there is no central database. Instead, entries are stored on individual nodes.
  // For simplicity, we will simulate this by storing the entry in a local file.
  FILE* file = fopen("fitness_tracker_database.txt", "a");
  fprintf(file, "%ld,%d,%d,%d\n", entry->timestamp, entry->steps, entry->caloriesBurned, entry->distanceTraveled);
  fclose(file);
}

// Get the total number of steps taken in a given day
int getTotalStepsTakenOnDay(time_t day) {
  // In a decentralized system, there is no central database. Instead, we need to query each node for data.
  // For simplicity, we will simulate this by reading the entries from a local file.
  FILE* file = fopen("fitness_tracker_database.txt", "r");
  int totalSteps = 0;
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    time_t timestamp;
    int steps, caloriesBurned, distanceTraveled;
    sscanf(line, "%ld,%d,%d,%d", &timestamp, &steps, &caloriesBurned, &distanceTraveled);
    if (timestamp >= day && timestamp < day + 86400) {
      totalSteps += steps;
    }
  }
  fclose(file);
  return totalSteps;
}

// Get the total number of calories burned in a given day
int getTotalCaloriesBurnedOnDay(time_t day) {
  // In a decentralized system, there is no central database. Instead, we need to query each node for data.
  // For simplicity, we will simulate this by reading the entries from a local file.
  FILE* file = fopen("fitness_tracker_database.txt", "r");
  int totalCaloriesBurned = 0;
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    time_t timestamp;
    int steps, caloriesBurned, distanceTraveled;
    sscanf(line, "%ld,%d,%d,%d", &timestamp, &steps, &caloriesBurned, &distanceTraveled);
    if (timestamp >= day && timestamp < day + 86400) {
      totalCaloriesBurned += caloriesBurned;
    }
  }
  fclose(file);
  return totalCaloriesBurned;
}

// Get the total distance traveled in a given day
int getTotalDistanceTraveledOnDay(time_t day) {
  // In a decentralized system, there is no central database. Instead, we need to query each node for data.
  // For simplicity, we will simulate this by reading the entries from a local file.
  FILE* file = fopen("fitness_tracker_database.txt", "r");
  int totalDistanceTraveled = 0;
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    time_t timestamp;
    int steps, caloriesBurned, distanceTraveled;
    sscanf(line, "%ld,%d,%d,%d", &timestamp, &steps, &caloriesBurned, &distanceTraveled);
    if (timestamp >= day && timestamp < day + 86400) {
      totalDistanceTraveled += distanceTraveled;
    }
  }
  fclose(file);
  return totalDistanceTraveled;
}

int main() {
  // Create a few sample fitness tracker entries
  FitnessTrackerEntry* entry1 = createFitnessTrackerEntry(time(NULL), 10000, 500, 5);
  FitnessTrackerEntry* entry2 = createFitnessTrackerEntry(time(NULL) + 3600, 5000, 250, 2.5);
  FitnessTrackerEntry* entry3 = createFitnessTrackerEntry(time(NULL) + 7200, 15000, 750, 7.5);

  // Add the entries to the decentralized database
  addFitnessTrackerEntryToDatabase(entry1);
  addFitnessTrackerEntryToDatabase(entry2);
  addFitnessTrackerEntryToDatabase(entry3);

  // Get the total number of steps taken on a given day
  time_t day = time(NULL) - 86400;
  int totalSteps = getTotalStepsTakenOnDay(day);
  printf("Total steps taken on %s: %d\n", ctime(&day), totalSteps);

  // Get the total number of calories burned on a given day
  int totalCaloriesBurned = getTotalCaloriesBurnedOnDay(day);
  printf("Total calories burned on %s: %d\n", ctime(&day), totalCaloriesBurned);

  // Get the total distance traveled on a given day
  int totalDistanceTraveled = getTotalDistanceTraveledOnDay(day);
  printf("Total distance traveled on %s: %d\n", ctime(&day), totalDistanceTraveled);

  return 0;
}