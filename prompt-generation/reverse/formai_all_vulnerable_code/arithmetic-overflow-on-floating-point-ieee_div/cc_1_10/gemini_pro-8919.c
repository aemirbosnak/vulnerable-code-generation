//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
  // Initialize variables
  struct rusage usage;
  long double user_time, system_time;
  int cpu_usage;

  // Get CPU usage information
  getrusage(RUSAGE_SELF, &usage);

  // Calculate user and system time in seconds
  user_time = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
  system_time = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;

  // Calculate CPU usage percentage
  cpu_usage = (int)((user_time + system_time) / sysconf(_SC_CLK_TCK) * 100);

  // Print CPU usage in a post-apocalyptic style
  printf("\n  __                                    __  .--..--..--..---.  \n");
  printf(" /  \\.---..---..---..---..---..---..---/  \\/    .-\  /    .-\  \ \n");
  printf("|  o |   ||   ||   ||   ||   ||   ||   ||  |   ( O|  ( O|  ( O|  |\n");
  printf("|     <   |   ||   ||   ||   ||   ||   ||  |    '.    '.    '.   | \n");
  printf("|  o |   ||   ||   ||   ||   ||   ||   ||  |  .--'  .--'  .--'  .--'| \n");
  printf("|     |   ||   ||   ||   ||   ||   ||   ||  /\:    /:    /:    /:    \n");
  printf("|     |   ||   ||   ||   ||   ||   ||   ||  \   \  /   \  /   \  /   |\n");
  printf(" \     |\ /|   |\ /|   |\ /|   |\ /|   |\     \/    \/    \/    \/    | \n");
  printf("   \   / | \   / | \   / | \   / | \   /  \                         \ \n");
  printf("    `-'  `-' `-'  `-' `-'  `-' `-'  `-'    `-------------------------'  \n");
  printf("                                                                        \n");
  printf("                    Wasteland CPU Monitor v1.0                            \n");
  printf("                                                                        \n");
  printf("   __...--~~~~~-._   _.-~~~~~--...__                                   \n");
  printf("  //               `V'               \\                                  \n");
  printf(" //                 |                 \\                                 \n");
  printf("||  o              |                 o  |                                \n");
  printf("||                 |                 ||                                 \n");
  printf("||                 |                 ||                                 \n");
  printf("||                 |                 ||                                 \n");
  printf("||                 |                 ||                                 \n");
  printf("||                 |                 ||                                 \n");
  printf("||                 |                 ||                                 \n");
  printf("||                                     ||                                 \n");
  printf("||                                     ||                                 \n");
  printf(" \                   // \\                   /                          \n");
  printf("   ~~~~~---.._      ||      _..---~~~~~                                \n");
  printf("               `----._||_..----'                                        \n");
  printf("                   ||   ||                                               \n");
  printf("                   \\   /                                                \n");
  printf("                    `-'                                                 \n\n");

  printf("  __               __  \n");
  printf(" /  \\.---..---..---/  \\ \n");
  printf("|  o |   ||   ||   ||  | \n");
  printf("|     <   |   ||   |   | \n");
  printf("|  o |   ||   ||   ||  | \n");
  printf("|     |   ||   ||   |   | \n");
  printf("|     |   ||   ||   |   | \n");
  printf(" \     |\ /|   |\ /|   /  \n");
  printf("   \   / | \   / | \   /    \n");
  printf("    `-'  `-' `-'  `-'      \n");

  printf("\nCPU Usage: %d%%\n\n", cpu_usage);

  return 0;
}