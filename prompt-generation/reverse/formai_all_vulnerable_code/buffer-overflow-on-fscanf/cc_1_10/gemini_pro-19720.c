//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our jolly disk space analyzer function
void analyzeDiskSpace() {

  // Start with a hearty greeting
  printf("Ahoy there, matey! Let's dig into your disk space, shall we?\n");

  // Get the current working directory
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    printf("Oops, something went wrong fetching your current directory. Time to swab the decks!\n");
    return;
  }

  // Calculate the total disk space
  long long totalSpace = 0;
  printf("Aye, let's calculate the total space ye be shiverin' on.\n");
  if (system("df -k | grep '^Filesystem' | awk '{print $2}'") == -1) {
    printf("Well shiver me timbers! Looks like we've got a mutiny on our hands. Can't seem to find yer total space.\n");
    return;
  }
  FILE *totalSpaceFile = popen("df -k | grep '^Filesystem' | awk '{print $2}'", "r");
  fscanf(totalSpaceFile, "%lld", &totalSpace);
  pclose(totalSpaceFile);

  // Calculate the used disk space
  long long usedSpace = 0;
  printf("Now, let's tally up the space ye be usin'.\n");
  if (system("df -k | grep '^Filesystem' | awk '{print $3}'") == -1) {
    printf("Avast! Looks like we're caught in a squall. Can't seem to find yer used space.\n");
    return;
  }
  FILE *usedSpaceFile = popen("df -k | grep '^Filesystem' | awk '{print $3}'", "r");
  fscanf(usedSpaceFile, "%lld", &usedSpace);
  pclose(usedSpaceFile);

  // Calculate the free disk space
  long long freeSpace = totalSpace - usedSpace;
  printf("And finally, let's see how much space ye be free to plunder.\n");

  // Print the results
  printf("Total space: %lld KB\n", totalSpace);
  printf("Used space: %lld KB\n", usedSpace);
  printf("Free space: %lld KB\n", freeSpace);

  // Cheerily bid farewell
  printf("Well, that's all for now, matey! May yer disk space be ever bountiful.\n");
}

int main() {
  // Set the stage for our jolly adventure
  printf("Welcome aboard, landlubber! Prepare to set sail on a grand voyage into the depths of your disk space.\n");

  // Embark on the disk space analysis journey
  analyzeDiskSpace();

  // Return to port with a hearty farewell
  printf("Yo ho ho, and a bottle of rum! Thanks for sailing with us, matey.\n");
  return 0;
}