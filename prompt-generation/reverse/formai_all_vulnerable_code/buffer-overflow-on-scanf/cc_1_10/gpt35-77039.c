//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
  
  // Welcome Message
  printf("Welcome to the Intrusion Detection System.\n");

  // Challenge User
  printf("Please enter the access key to proceed: ");
  
  // Read Input
  char accessKey[10];
  scanf("%s", accessKey);

  // Initialise Random Generator
  srand(time(NULL));

  // Generate Random Key
  char randomKey[10];
  for(int i=0; i<9; i++){
    randomKey[i] = (rand() % 26) + 65;
  }
  randomKey[9] = '\0';

  // Compare User Input with Random Key
  if(strcmp(accessKey, randomKey) == 0){

    // Access Granted
    printf("Access Granted!\n");

    // Initialise Log
    FILE *logFile;
    logFile = fopen("log.txt", "w");
    fprintf(logFile, "Access Granted at %s", __TIME__);
    fclose(logFile);
    
    // Wait For 10 Seconds
    printf("System is monitoring your activity for any suspicious behavior.\nPlease wait for 10 seconds...\n");
    sleep(10);

    // Check Log File
    logFile = fopen("log.txt", "r");
    char logContent[100];
    fscanf(logFile, "%s", logContent);
    fclose(logFile);

    // Display Log Content
    printf("System Log: %s\n", logContent);

    // End Program
    return 0;

  } else {

    // Access Denied
    printf("Access Denied!\n");

    // Initialise Log
    FILE *logFile;
    logFile = fopen("log.txt", "w");
    fprintf(logFile, "Access Denied at %s", __TIME__);
    fclose(logFile);

    // End Program
    return 1;
  }
}