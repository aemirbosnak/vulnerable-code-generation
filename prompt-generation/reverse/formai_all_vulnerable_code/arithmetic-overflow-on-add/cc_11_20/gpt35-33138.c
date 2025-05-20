//FormAI DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>

int main() {
  int num_of_guilds = 5;
  int num_of_knights = 10;
  int num_of_servants = 20;
  
  int choice;
  printf("Welcome, Lord Administrator. What would you like to do?\n");
  printf("1. Recruit more knights\n");
  printf("2. Hire more servants\n");
  printf("3. Assign tasks to knights and servants\n");
  printf("4. Check guild status\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("How many knights would you like to recruit?\n");
      int num_recruits;
      scanf("%d", &num_recruits);
      num_of_knights += num_recruits;
      printf("%d knights have been added to your guild.\n", num_recruits);
      break;
      
    case 2:
      printf("How many servants would you like to hire?\n");
      int num_hires;
      scanf("%d", &num_hires);
      num_of_servants += num_hires;
      printf("%d servants have been hired to work in your guild.\n", num_hires);
      break;
      
    case 3:
      printf("What tasks would you like to assign?\n");
      printf("1. Guard duty\n");
      printf("2. Patrol duty\n");
      printf("3. Supply run\n");
      printf("Enter your choice: ");
      int task_choice;
      scanf("%d", &task_choice);
      switch(task_choice) {
        case 1:
          printf("How many knights would you like to assign to guard duty?\n");
          int num_guards;
          scanf("%d", &num_guards);
          if(num_guards > num_of_knights) {
            printf("You do not have enough knights. Please recruit more.\n");
          } else {
            num_of_knights -= num_guards;
            printf("%d knights have been assigned to guard duty.\n", num_guards);
          }
          break;
          
        case 2:
          printf("How many knights would you like to assign to patrol duty?\n");
          int num_patrols;
          scanf("%d", &num_patrols);
          if(num_patrols > num_of_knights) {
            printf("You do not have enough knights. Please recruit more.\n");
          } else {
            num_of_knights -= num_patrols;
            printf("%d knights have been assigned to patrol duty.\n", num_patrols);
          }
          break;
          
        case 3:
          printf("How many servants would you like to assign to supply run?\n");
          int num_supplies;
          scanf("%d", &num_supplies);
          if(num_supplies > num_of_servants) {
            printf("You do not have enough servants. Please hire more.\n");
          } else {
            num_of_servants -= num_supplies;
            printf("%d servants have been assigned to supply run.\n", num_supplies);
          }
          break;
          
        default:
          printf("Invalid choice.");
          break;
      }
      break;
      
    case 4:
      printf("Your guild has %d knights and %d servants.\n", num_of_knights, num_of_servants);
      break;
      
    default:
      printf("Invalid choice.");
      break;
  }
  
  return 0;
}