//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SENSOR_GPIO 4
#define LED_GPIO 17
#define TEMP_THRESHOLD 30

void setup() {
    printf("Initializing...\n");
    system("gpio -g mode 4 in");
    system("gpio -g mode 17 out");
    system("gpio -g write 17 1");
}

int main() {
    setup();

    while (1) {
        int temperature = get_temperature();
        printf("Current temperature: %d°C\n", temperature);

        if (temperature > TEMP_THRESHOLD) {
            printf("Temperature is too high, turning on LED...\n");
            system("gpio -g write 17 0");
        } else {
            printf("Temperature is normal, turning off LED...\n");
            system("gpio -g write 17 1");
        }

        sleep(10);
    }

    return 0;
}

int get_temperature() {
    FILE *fp;
    char line[100];
    int temperature = 0;

    fp = popen("vcgencmd measure_temp", "r");
    if (fp!= NULL) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "temp=%d.%d", &temperature, &temperature);
        pclose(fp);
    }

    return temperature;
}