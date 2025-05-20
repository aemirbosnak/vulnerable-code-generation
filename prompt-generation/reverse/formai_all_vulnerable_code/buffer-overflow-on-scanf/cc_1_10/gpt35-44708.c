//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  // Define suspicious characters
  char *suspicious[] = {"root", "password", "admin", "123456", "qwerty", "letmein", "monkey", "abc123", "welcome", "passw0rd"};
  int num_suspicious = sizeof(suspicious) / sizeof(suspicious[0]);
  
  // Define variable to keep track of number of suspicious attempts
  int num_attempts = 0;
  
  // Define variable to randomly generate number between 0 and 99
  int random_num;

  // Loop to simulate login attempts
  while(1) {
    // Generate random number
    random_num = rand() % 100;

    // Prompt user for username and password
    char username[20], password[20];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Check if username or password contains suspicious characters
    int i;
    for(i = 0; i < num_suspicious; i++) {
      if(strstr(username, suspicious[i]) != NULL || strstr(password, suspicious[i]) != NULL) {
        num_attempts++;
        printf("\nWARNING: Suspicious characters detected in username or password. Number of suspicious attempts: %d\n\n", num_attempts);
        
        // Check if number of suspicious attempts has reached a certain threshold
        if(num_attempts >= 5) {
          printf("INTRUSION DETECTED. SYSTEM SHUTTING DOWN.\n");
          return 0;
        }
        
        break;
      }
    }

    // Generate random number and compare to threshold to simulate system being compromised
    if(random_num >= 95) {
      printf("\nWARNING: SYSTEM COMPROMISED. Number of suspicious attempts: %d\n\n", num_attempts);
      
      // Check if number of suspicious attempts has reached a certain threshold
      if(num_attempts >= 5) {
        printf("INTRUSION DETECTED. SYSTEM SHUTTING DOWN.\n");
        return 0;
      } else {
        num_attempts++;
      }
    } else {
      printf("\nACCESS GRANTED.\n\n");
      num_attempts = 0;
    }
  }

  return 0;
}