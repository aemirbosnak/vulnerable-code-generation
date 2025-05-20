//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> 

int main() {

  struct tm *local_time;
  time_t time_now;
  char time_buf[128];
  
  //initialize firewall rules
  int ssh_allowed = 0;  
  int http_allowed = 0;
  int ftp_allowed = 0;
  
  printf("Firewall initialized. Blocking all incoming traffic...\n");
  
  while(1) { //continuous loop for firewall

    //get current time
    time_now = time(NULL);
    local_time = localtime(&time_now);
    strftime(time_buf, sizeof(time_buf), "%m/%d/%Y %H:%M:%S", local_time);
    
    //check for incoming traffic
    int incoming_ssh = rand() % 2; //randomly generated incoming ssh traffic
    int incoming_http = rand() % 2; //randomly generated incoming http traffic
    int incoming_ftp = rand() % 2; //randomly generated incoming ftp traffic
    
    if(incoming_ssh && !ssh_allowed) { //if incoming ssh traffic and not allowed
      printf("%s Incoming SSH traffic detected. Blocking access.\n", time_buf);
      continue; //continue to next iteration of while loop
    }
    
    if(incoming_http && !http_allowed) {
      printf("%s Incoming HTTP traffic detected. Blocking access.\n", time_buf);
      continue;
    }
    
    if(incoming_ftp && !ftp_allowed) {
      printf("%s Incoming FTP traffic detected. Blocking access.\n", time_buf);
      continue;
    }
    
    printf("No incoming traffic detected.\n"); //if no blocked traffic
    
    //ask user to allow certain traffic
    printf("Do you want to allow SSH traffic? (Type 'yes' or 'no')\n");
    char user_input[10];
    scanf("%s", user_input);
    
    if(strcmp(user_input, "yes") == 0) { //if user allows ssh traffic
      ssh_allowed = 1;
      printf("SSH traffic allowed.\n");
    }
    
    printf("Do you want to allow HTTP traffic? (Type 'yes' or 'no')\n");
    scanf("%s", user_input);
    
    if(strcmp(user_input, "yes") == 0) {
      http_allowed = 1;
      printf("HTTP traffic allowed.\n");
    }
    
    printf("Do you want to allow FTP traffic? (Type 'yes' or 'no')\n");
    scanf("%s", user_input);
    
    if(strcmp(user_input, "yes") == 0) {
      ftp_allowed = 1;
      printf("FTP traffic allowed.\n");
    }
    
    sleep(1); //wait one second before checking for traffic again
    
  }
  
  return 0; //end of program
  
}