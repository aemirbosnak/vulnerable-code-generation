//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet GPS Navigation Simulation
// Verona, Italy

// Define Verona street names
char* streets[] = {
  "Via Capello",
  "Via Mazzini",
  "Via Scala",
  "Via Cappello",
  "Via Roma",
  "Via Cavour",
  "Via San Carlo",
  "Via Mazzini",
  "Via Scala",
  "Via Cappello",
  "Via Roma",
  "Via Cavour",
  "Via San Carlo"
};

// Define Romeo and Juliet starting locations
int romeo_start = 0;
int juliet_start = 9;

// Define GPS navigation guidance messages
char* guidance_messages[] = {
  "Go forth, Romeo, to Verona's heart,",
  "Where ancient streets await your art.",
  "Turn right onto Via Mazzini's grace,",
  "And seek thy love in Juliet's embrace.",
  "Proceed to Via Scala, where fate resides,",
  "And destiny a rendezvous provides.",
  "Turn left onto Via Cappello's way,",
  "Where love's embrace awaits you, they say.",
  "Continue straight on Via Roma's grand,",
  "Until Cavour's embrace you understand.",
  "Turn right again to San Carlo's light,",
  "Where love's eternal flame burns bright."
};

// Print GPS navigation guidance message
void print_guidance(int step) {
  printf("%s\n", guidance_messages[step]);
}

// Simulate Romeo's journey to Juliet
void romeo_journey() {
  int current_location = romeo_start;
  int step = 0;
  
  // Iterate through navigation steps
  while (current_location != juliet_start) {
    print_guidance(step);
    
    // Advance to next street
    if (current_location % 2 == 0) {
      current_location += 2;
    } else {
      current_location--;
    }
    
    step++;
  }
  
  // Final message
  printf("Romeo and Juliet reunited, their hearts aflame,\nIn Verona's embrace, their love's eternal claim.\n");
}

int main() {
  // Start Romeo's journey to Juliet
  romeo_journey();
  
  return 0;
}