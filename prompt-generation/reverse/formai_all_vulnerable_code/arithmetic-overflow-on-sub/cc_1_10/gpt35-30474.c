//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to check website status
int check_website_status() {
  // generate random status code (200, 404, 500)
  int random_status = rand() % 3;
  
  if (random_status == 0) {
    return 200;
  }
  else if (random_status == 1) {
    return 404;
  }
  else {
    return 500;
  }
}

// main function to monitor website uptime
int main() {
  // initialize variables
  int status_code;
  clock_t start_time, end_time;
  double elapsed_time;

  // website to monitor
  char website[] = "https://example.com";
  
  while (1) {
    // get start time
    start_time = clock();
    
    // check website status
    status_code = check_website_status();
    
    // get end time
    end_time = clock();
    
    // calculate elapsed time
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // print website status and response time
    printf("Website: %s | Status Code: %d | Response Time: %f seconds\n", website, status_code, elapsed_time);
    
    // wait for 5 seconds before checking again
    sleep(5);
  }

  return 0;
}