//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>

#define JOYSTICK_DEV "/dev/input/js0"

int main()
{
	int fd;
	struct js_event event;
	int i;
	int axis[6];
	int button[12];
	int quit = 0;

	fd = open(JOYSTICK_DEV, O_RDONLY);
	if (fd < 0) {
		perror("open");
		return EXIT_FAILURE;
	}

	while (!quit) {
		read(fd, &event, sizeof(event));

		switch (event.type) {
		case JS_EVENT_BUTTON:
			button[event.number] = event.value;
			break;
		case JS_EVENT_AXIS:
			axis[event.number] = event.value;
			break;
		}

		printf("Event: type %d, number %d, value %d\n", event.type, event.number, event.value);

		if (button[9]) {
			quit = 1;
		}

		if (axis[0] < -10000) {
			printf("Left\n");
		} else if (axis[0] > 10000) {
			printf("Right\n");
		}

		if (axis[1] < -10000) {
			printf("Up\n");
		} else if (axis[1] > 10000) {
			printf("Down\n");
		}

		if (axis[2] < -10000) {
			printf("Trigger\n");
		}

		if (axis[3] < -10000) {
			printf("Throttle\n");
		}

		if (axis[4] < -10000) {
			printf("Roll\n");
		} else if (axis[4] > 10000) {
			printf("Pitch\n");
		}

		if (axis[5] < -10000) {
			printf("Yaw\n");
		} else if (axis[5] > 10000) {
			printf("Yaw\n");
		}
	}

	close(fd);

	return EXIT_SUCCESS;
}