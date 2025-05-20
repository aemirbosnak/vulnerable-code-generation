//Code Llama-13B DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>

  #define LOG_FILE "/var/log/syslog"
  #define LOG_LEVEL 7

  typedef struct {
    char *name;
    char *description;
    int level;
  } event_t;

  event_t events[] = {
    { "SYS_BOOT", "System boot event", 1 },
    { "SYS_SHUTDOWN", "System shutdown event", 1 },
    { "SYS_CRASH", "System crash event", 3 },
    { "SYS_MEMORY_ALERT", "Memory usage alert event", 5 },
    { "SYS_DISK_SPACE_ALERT", "Disk space usage alert event", 5 },
    { "SYS_PROCESS_ALERT", "Process alert event", 7 },
  };

  int main(int argc, char *argv[]) {
    int i;
    int fd;
    char *event_name;
    char *event_description;
    int event_level;

    if (argc < 3) {
      printf("Usage: %s <event_name> <event_description> <event_level>\n", argv[0]);
      return 1;
    }

    event_name = argv[1];
    event_description = argv[2];
    event_level = atoi(argv[3]);

    if (event_level > LOG_LEVEL) {
      printf("Invalid event level\n");
      return 1;
    }

    fd = open(LOG_FILE, O_WRONLY | O_APPEND);
    if (fd < 0) {
      printf("Error opening log file\n");
      return 1;
    }

    for (i = 0; i < sizeof(events) / sizeof(events[0]); i++) {
      if (strcmp(events[i].name, event_name) == 0) {
        event_level = events[i].level;
        event_description = events[i].description;
        break;
      }
    }

    if (event_level <= LOG_LEVEL) {
      char buf[1024];
      snprintf(buf, sizeof(buf), "[%s] %s (%s)\n", event_name, event_description, event_level);
      write(fd, buf, strlen(buf));
    }

    close(fd);
    return 0;
  }