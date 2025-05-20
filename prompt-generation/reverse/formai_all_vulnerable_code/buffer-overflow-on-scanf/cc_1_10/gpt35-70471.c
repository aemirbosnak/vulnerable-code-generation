//FormAI DATASET v1.0 Category: System boot optimizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("C System Boot Optimizer\n");
  printf("-----------------------\n\n");

  //Declare variables to store system information
  int num_cores;
  double cpu_speed;
  int ram_size;

  //Get system information from the user
  printf("Enter number of CPU cores: ");
  scanf("%d", &num_cores);

  printf("Enter CPU speed (GHz): ");
  scanf("%lf", &cpu_speed);

  printf("Enter RAM size (GB): ");
  scanf("%d", &ram_size);

  //Calculate boot time based on system information
  double boot_time = 0.0;

  //Calculate the time taken for each component to load
  double cpu_load_time = 0.10 * num_cores / cpu_speed; //Assuming 10% of CPU is used during boot
  double ram_load_time = 0.05 * ram_size; //Assuming 5% of RAM is used during boot
  double disk_load_time = 20.0; //Assuming 20 seconds to load from disk

  boot_time = cpu_load_time + ram_load_time + disk_load_time;

  //Print estimated boot time to the user
  printf("\nEstimated boot time: %0.2lf seconds\n\n", boot_time);

  //Optimize boot time based on system information
  if (boot_time > 30.0) { //If boot time is greater than 30 seconds, optimize
    printf("Boot time optimization in progress...\n\n");

    //Reduce time taken for CPU to load
    if (num_cores >= 4 && cpu_speed >= 2.0) {
      printf("Optimizing CPU load time...\n");
      cpu_load_time = 0.05 * num_cores / cpu_speed; //Assuming 5% of CPU is used during boot
    }

    //Reduce time taken for RAM to load
    if (ram_size >= 8) {
      printf("Optimizing RAM load time...\n");
      ram_load_time = 0.02 * ram_size; //Assuming 2% of RAM is used during boot
    }

    //Reduce time taken for disk to load
    printf("Optimizing disk load time...\n");
    disk_load_time = 15.0; //Assuming 15 seconds to load from disk

    //Recalculate boot time after optimization
    boot_time = cpu_load_time + ram_load_time + disk_load_time;

    //Print optimized boot time to the user
    printf("\nOptimized boot time: %0.2lf seconds\n\n", boot_time);
  } else { //If boot time is less than or equal to 30 seconds, no need for optimization
    printf("Boot time is optimal for the given system configuration.\n");
  }

  //Exit program
  return 0;
}