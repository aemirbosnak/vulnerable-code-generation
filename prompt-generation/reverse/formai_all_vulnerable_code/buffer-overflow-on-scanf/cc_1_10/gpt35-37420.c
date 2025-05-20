//FormAI DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>

// Define the structure to store the data
typedef struct {
  char url[200];
  int visits;
} SiteInfo;

// Define the function to update the visits
void updateVisits(char* url, SiteInfo* sites, int numSites) {
  int i;

  // Loop through all the sites to find the one being updated
  for (i = 0; i < numSites; i++) {
    if (strcmp(url, sites[i].url) == 0) {
      sites[i].visits++;
      return;
    }
  }

  // If the site was not found, create a new entry for it
  strcpy(sites[numSites].url, url);
  sites[numSites].visits = 1;
}

// Define the function to sort the data
void sortData(SiteInfo* sites, int numSites) {
  int i, j;
  SiteInfo temp;

  // Use bubble sort to sort the data
  for (i = 0; i < numSites-1; i++) {
    for (j = 0; j < numSites-i-1; j++) {
      if (sites[j].visits < sites[j+1].visits) {
        temp = sites[j];
        sites[j] = sites[j+1];
        sites[j+1] = temp;
      }
    }
  }
}

// Define the function to display the data
void displayData(SiteInfo* sites, int numSites) {
  int i;

  printf("Top 10 Sites\n");
  printf("-------------\n");
  
  // Display the top 10 sites
  for (i = 0; i < 10 && i < numSites; i++) {
    printf("%d. %s (%d visits)\n", i+1, sites[i].url, sites[i].visits);
  }
}

// Define the main function
int main() {
  char url[200];
  SiteInfo sites[1000];
  int numSites = 0;

  // Continuously prompt the user for input
  while (1) {
    printf("Enter URL (or 'q' to quit): ");
    scanf("%s", url);

    // Check if the user wants to quit
    if (strcmp(url, "q") == 0) {
      break;
    }

    // Update the data and sort it
    updateVisits(url, sites, numSites);
    numSites++;
    sortData(sites, numSites);

    // Display the data
    displayData(sites, numSites);
  }

  return 0;
}