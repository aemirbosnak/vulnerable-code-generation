//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include <stdio.h>

#define NUM_FLOORS 10 // number of floors
#define CAPACITY 10 // capacity of the elevator
#define MAX_COMMANDS 20 // maximum number of commands that can be entered

int current_floor = 1; // initialize to first floor
int num_passengers = 0; // initialize to zero
int commands[MAX_COMMANDS]; // array to hold commands
int num_commands = 0; // initialize to zero

void print_current_floor(void) {
  printf("You are currently on floor %d.\n", current_floor);
}

void print_num_passengers(void) {
  printf("There are currently %d passengers in the elevator.\n", num_passengers);
}

void print_commands(void) {
  printf("The following commands have been entered:\n");
  for (int i = 0; i < num_commands; i++) {
    printf("%d ", commands[i]);
  }
  printf("\n");
}

void add_command(int command) {
  if (num_commands == MAX_COMMANDS) {
    printf("Maximum number of commands reached. Command not added.\n");
  } else {
    commands[num_commands] = command;
    num_commands++;
  }
}

void execute_command(int command) {
  switch (command) {
    case 0:
      current_floor++;
      print_current_floor();
      break;
    case 1:
      current_floor--;
      print_current_floor();
      break;
    case 2:
      printf("Doors opening...\n");
      printf("Doors closing...\n");
      break;
    case 3:
      if (num_passengers == CAPACITY) {
        printf("Maximum capacity reached. Passenger not added.\n");
      } else {
        num_passengers++;
        print_num_passengers();
      }
      break;
    case 4:
      if (num_passengers == 0) {
        printf("No passengers to remove.\n");
      } else {
        num_passengers--;
        print_num_passengers();
      }
      break;
    default:
      printf("Invalid command.\n");
      break;
  }
}

int main(void) {
  char input[10];
  int command;
  while (1) {
    printf("Enter a command (0 = up, 1 = down, 2 = open/close doors, 3 = add passenger, 4 = remove passenger): ");
    fgets(input, 10, stdin);
    sscanf(input, "%d", &command);
    if (command >= 0 && command <= 4) {
      add_command(command);
      execute_command(command);
      if (num_passengers > 0) {
        printf("Press any key to continue...");
        getchar();
      }
    } else {
      printf("Invalid command.\n");
    }
    print_commands();
  }
  return 0;
}