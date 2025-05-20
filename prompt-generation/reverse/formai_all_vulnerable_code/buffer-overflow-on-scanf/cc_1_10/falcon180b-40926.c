//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define GPIO_DIR "/sys/class/gpio/gpiochip0/direction"
#define GPIO_VAL "/sys/class/gpio/gpio%d/value"

#define LED_PIN 4

int main() {

	int fd;
	char value[10];

	fd = open(GPIO_DIR, O_RDWR);

	if (fd < 0) {
		printf("Error opening GPIO direction\n");
		return 1;
	}

	dprintf(fd, "4 out");

	fd = open(GPIO_VAL, O_RDWR);

	if (fd < 0) {
		printf("Error opening GPIO value\n");
		return 1;
	}

	while (1) {
		printf("Enter new LED state (0 or 1): ");
		scanf("%s", value);

		if (value[0] == '0') {
			dprintf(fd, "0");
		} else if (value[0] == '1') {
			dprintf(fd, "1");
		} else {
			printf("Invalid input\n");
		}
	}

	return 0;
}